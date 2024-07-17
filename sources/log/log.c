#include "log.h"

#include "defines/efi_status_defines.h"

static EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *ConsoleOut = NULL_PTR;

static UINT64 _IntToString(OUT CHAR16 *Buffer, IN INT64 Value);
static VOID _LogInt(IN CONST CHAR16 *Info, IN INT64 Value);
static VOID _LogIntPair(IN CONST CHAR16 *Info, IN INT64 FirstValue, IN INT64 SecondValue);
static VOID _LogHex(IN CONST CHAR16 *Info, IN UINT64 Value);

STATUS EFI_API LogInitialize(IN CONST EFI_SYSTEM_TABLE *SystemTable)
{
    STATUS Status = E_OK;

    if (NULL_PTR == SystemTable)
    {
        Status = E_NOT_OK;
        goto Cleanup;
    }

    if (NULL_PTR == SystemTable->ConsoleOut)
    {
        Status = E_NOT_OK;
        goto Cleanup;
    }

    ConsoleOut = SystemTable->ConsoleOut;
    ConsoleOut->Reset(ConsoleOut, TRUE);
    ConsoleOut->SetMode(ConsoleOut, 3);
    ConsoleOut->SetAttribute(ConsoleOut, EFI_BACKGROUND_BLUE | EFI_WHITE);
    ConsoleOut->ClearScreen(ConsoleOut);

Cleanup:
    if (E_OK != Status)
    {
        ConsoleOut = NULL_PTR;
    }

    return Status;
}

STATUS LogClearScreen(VOID)
{
    STATUS Status = E_OK;

    ConsoleOut->ClearScreen(ConsoleOut);

    return Status;
}

STATUS EFI_API LogString(IN CONST CHAR16 *OutputString)
{
    STATUS Status = E_OK;
    EFI_STATUS EfiStatus = EFI_SUCCESS;

    if (NULL_PTR == ConsoleOut)
    {
        Status = E_NOT_OK;
        goto Cleanup;
    }

    EfiStatus = ConsoleOut->OutputString(ConsoleOut, (CHAR16 *)OutputString);
    if (EFI_SUCCESS != EfiStatus)
    {
        Status = E_NOT_OK;
        goto Cleanup;
    }

Cleanup:
    return Status;
}

STATUS EFI_API LogHighlightedString(IN CONST CHAR16 *OutputString)
{
    STATUS Status = E_OK;

    ConsoleOut->SetAttribute(ConsoleOut, EFI_BACKGROUND_LIGHTGRAY | EFI_BLACK);
    ConsoleOut->OutputString(ConsoleOut, (CHAR16 *)OutputString);
    ConsoleOut->SetAttribute(ConsoleOut, EFI_BACKGROUND_BLUE | EFI_WHITE);

    return Status;
}

STATUS EFI_API LogInt(IN CONST CHAR16 *Info, INT64 Value)
{
    STATUS Status = E_OK;

    _LogInt(Info, Value);

    return Status;
}

STATUS EFI_API LogIntPair(IN CONST CHAR16 *Info, INT64 FirstValue, INT64 SecondValue)
{
    STATUS Status = E_OK;

    _LogIntPair(Info, FirstValue, SecondValue);

    return Status;
}

STATUS EFI_API LogHighlightedIntPair(IN CONST CHAR16 *Info, INT64 FirstValue, INT64 SecondValue)
{
    STATUS Status = E_OK;

    ConsoleOut->SetAttribute(ConsoleOut, EFI_BACKGROUND_LIGHTGRAY | EFI_BLACK);
    _LogIntPair(Info, FirstValue, SecondValue);
    ConsoleOut->SetAttribute(ConsoleOut, EFI_BACKGROUND_BLUE | EFI_WHITE);

    return Status;
}

STATUS EFI_API LogHex(IN CONST CHAR16 *Info, UINT64 Value)
{
    STATUS Status = E_OK;

    _LogHex(Info, Value);

    return Status;
}

STATUS EFI_API LogBuffer(IN CONST UINT8 *Buffer, UINT64 BufferSize)
{
    STATUS Status = E_OK;

    for (UINT64 index = 0; index < BufferSize; ++index)
    {
        LogHex(u"", Buffer[index] / 16);
        LogHex(u"", Buffer[index] % 16);
        LogString(u" ");
    }

    return Status;
}

static UINT64 _HexToString(OUT CHAR16 *Buffer, IN UINT64 Value)
{
    UINT64 BufferSize = 0;

    do
    {
        if (Value % 16 < 10)
        {
            Buffer[BufferSize] = (Value % 16) + '0';
        }
        else
        {
            Buffer[BufferSize] = (Value % 16) + 'A' - 10;
        }
        BufferSize++;
        Value /= 16;
    } while (0 != Value);

    for (UINT64 index = 0; index < BufferSize / 2; ++index)
    {

        CHAR16 SwapChar = Buffer[index];
        Buffer[index] = Buffer[BufferSize - index - 1];
        Buffer[BufferSize - index - 1] = SwapChar;
    }

    return BufferSize;
}

static UINT64 _IntToString(OUT CHAR16 *Buffer, IN INT64 Value)
{
    UINT64 BufferSize = 0;
    UINT64 Sign = 0;

    if (Value < 0)
    {
        Value = -Value;
        Buffer[BufferSize] = u'-';
        Buffer++;
        Sign = 1;
    }

    do
    {
        Buffer[BufferSize] = (Value % 10) + '0';
        BufferSize++;
        Value /= 10;
    } while (0 != Value);

    for (UINT64 index = 0; index < BufferSize / 2; ++index)
    {

        CHAR16 SwapChar = Buffer[index];
        Buffer[index] = Buffer[BufferSize - index - 1];
        Buffer[BufferSize - index - 1] = SwapChar;
    }

    return BufferSize + Sign;
}

static VOID _LogInt(IN CONST CHAR16 *Info, IN INT64 Value)
{
    CHAR16 Buffer[1024];
    UINT64 BufferSize = 0;

    for (UINT64 index = 0; 0 != Info[index]; ++index)
    {
        Buffer[BufferSize] = Info[index];
        BufferSize++;
    }

    BufferSize += _IntToString(Buffer + BufferSize, Value);
    Buffer[BufferSize++] = '\r';
    Buffer[BufferSize++] = '\n';
    Buffer[BufferSize++] = 0;

    ConsoleOut->OutputString(ConsoleOut, Buffer);
}

static VOID _LogIntPair(IN CONST CHAR16 *Info, IN INT64 FirstValue, IN INT64 SecondValue)
{
    CHAR16 Buffer[1024];
    UINT64 BufferSize = 0;

    for (UINT64 index = 0; 0 != Info[index]; ++index)
    {
        Buffer[BufferSize] = Info[index];
        BufferSize++;
    }

    BufferSize += _IntToString(Buffer + BufferSize, FirstValue);
    Buffer[BufferSize++] = 'x';
    BufferSize += _IntToString(Buffer + BufferSize, SecondValue);
    Buffer[BufferSize++] = '\r';
    Buffer[BufferSize++] = '\n';
    Buffer[BufferSize++] = 0;

    ConsoleOut->OutputString(ConsoleOut, Buffer);
}

static VOID _LogHex(IN CONST CHAR16 *Info, IN UINT64 Value)
{
    CHAR16 Buffer[1024];
    UINT64 BufferSize = 0;

    for (UINT64 index = 0; 0 != Info[index]; ++index)
    {
        Buffer[BufferSize] = Info[index];
        BufferSize++;
    }

    BufferSize += _HexToString(Buffer + BufferSize, Value);
    Buffer[BufferSize++] = 0;

    ConsoleOut->OutputString(ConsoleOut, Buffer);
}
