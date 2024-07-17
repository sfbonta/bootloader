#include "menu.h"

#include "log.h"
#include "efi_status_defines.h"
#include "protocols/efi_graphics_output_protocol.h"
#include "protocols/efi_loaded_image_protocol.h"
#include "protocols/efi_simple_file_system_protocol.h"
#include "protocols/efi_file_protocol.h"
#include "protocols/efi_hii_font_protocol.h"
#include "kernel_arguments.h"
#include "video_adapter.h"
#include "hii_loader.h"
#include "system_memory_types.h"
#include "acpi2.h"
#include "utils.h"
#include "elf_parser.h"

static const CHAR16 *MenuEntries[] = {
    u"Set Text Mode\r\n",
    u"Set Video Mode\r\n",
    u"File Explorer\r\n",
    u"Load Kernel\r\n",
};
static const UINT64 NumberOfEntries = 4;
static UINT64 HighlightedOption = 0;
static UINT64 HighlightedTextModeOption = 0;
static UINT64 HighlightedGraphicsModeOption = 0;
static UINT64 HighlightedFileExplorerOption = 0;

static EFI_HANDLE Handle;
static EFI_SYSTEM_TABLE *SystemTableG = NULL_PTR;
static EFI_BOOT_SERVICES *BootServices = NULL_PTR;
static EFI_RUNTIME_SERVICES *RuntimeServices = NULL_PTR;
static EFI_GRAPHICS_OUTPUT_PROTOCOL *Gop = NULL_PTR;
static EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *Cout = NULL_PTR;
static EFI_SIMPLE_TEXT_INPUT_PROTOCOL *Cin = NULL_PTR;
static EFI_FILE_PROTOCOL *Fp = NULL_PTR;
static EFI_FILE_PROTOCOL *KernelFp = NULL_PTR;
static EFI_HII_FONT_PROTOCOL *Hiifp = NULL_PTR;

static VOID SimpleTextInputProtocolInit(VOID);
static VOID GraphicsOutputProtocolInit(VOID);
static VOID FileExplorerInit(VOID);
static VOID HiiFontInit(VOID);

static VOID SetTextModeLoop(VOID);
static VOID SetGraphicsModeLoop(VOID);
static VOID FileExplorerLoop(VOID);
static VOID LoadKernel(VOID);

static STATUS API AllocateMemory(OUT VOID **Buffer, IN CONST UINT64 Size);

static VOID StrcpyU16(CHAR16 *Source, CHAR16 *Destination)
{
    UINT64 index = 0;
    for (index = 0; Source[index] != 0; index++)
    {
        Destination[index] = Source[index];
    }
    Destination[index] = 0;
}

static VOID (*MenuEntriesFunctions[])(VOID) = {
    SetTextModeLoop,
    SetGraphicsModeLoop,
    FileExplorerLoop,
    LoadKernel,
};

VOID MenuInit(EFI_SYSTEM_TABLE *SystemTable, EFI_HANDLE ImageHandle)
{
    SystemTableG = SystemTable;
    BootServices = SystemTable->BootServices;
    RuntimeServices = SystemTable->RuntimeServices;
    Cout = SystemTable->ConsoleOut;
    Cin = SystemTable->ConsoleIn;
    Handle = ImageHandle;

    LogInitialize(SystemTable);
    SimpleTextInputProtocolInit();
    GraphicsOutputProtocolInit();
    FileExplorerInit();
    HiiFontInit();
}

VOID MenuLoop(VOID)
{
    LogClearScreen();
    for (UINT64 index = 0; index < NumberOfEntries; ++index)
    {
        if (index == HighlightedOption)
        {
            LogHighlightedString(MenuEntries[index]);
        }
        else
        {
            LogString(MenuEntries[index]);
        }
    }

    EFI_INPUT_KEY Key;
    while (0 != Cin->ReadKey(Cin, &Key))
        ;

    switch (Key.ScanCode)
    {
    case 0x01:
        if (0 != HighlightedOption)
        {
            HighlightedOption--;
        }
        break;

    case 0x02:
        if (NumberOfEntries - 1 != HighlightedOption)
        {
            HighlightedOption++;
        }
        break;

    case 0x03:
        MenuEntriesFunctions[HighlightedOption]();
        break;

    case 0x17:
        RuntimeServices->ResetSystem(EfiResetShutdown, EFI_SUCCESS, 0, NULL_PTR);
        break;

    default:
        break;
    }
}

static VOID SimpleTextInputProtocolInit(VOID)
{
    Cin->Reset(Cin, FALSE);
}

static VOID GraphicsOutputProtocolInit(VOID)
{
    EFI_GUID GraphicsOutputProtocolGuid = EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID;
    BootServices->LocateProtocol(&GraphicsOutputProtocolGuid, NULL_PTR, (VOID **)&Gop);
    Gop->SetMode(Gop, 18);
}

static VOID FileExplorerInit(VOID)
{
    EFI_GUID LoadedImageProtocolGuid = EFI_LOADED_IMAGE_PROTOCOL_GUID;
    EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *Sfsp = NULL_PTR;
    EFI_LOADED_IMAGE_PROTOCOL *Lip = NULL_PTR;
    EFI_GUID SfspGuid = EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID;

    BootServices->OpenProtocol(Handle, &LoadedImageProtocolGuid, (VOID **)&Lip, Handle, NULL_PTR, EFI_OPEN_PROTOCOL_BY_HANDLE_PROTOCOL);
    BootServices->OpenProtocol(Lip->DeviceHandle, &SfspGuid, (VOID **)&Sfsp, Handle, NULL_PTR, EFI_OPEN_PROTOCOL_BY_HANDLE_PROTOCOL);
    Sfsp->OpenVolume(Sfsp, &Fp);
    KernelFp = Fp;
}

static VOID HiiFontInit(VOID)
{
    EFI_GUID HiiFontProtocolGuid = EFI_HII_FONT_PROTOCOL_GUID;
    BootServices->LocateProtocol(&HiiFontProtocolGuid, NULL_PTR, (VOID **)&Hiifp);
}

static VOID SetTextModeLoop(VOID)
{
    while (1)
    {
        LogClearScreen();

        LogInt(u"Number of modes: ", Cout->Mode->MaxMode);
        LogInt(u"Current Mode: ", Cout->Mode->Mode);
        for (UINT64 index = 0; index < (UINT64)Cout->Mode->MaxMode; ++index)
        {
            UINTN NumberOfColumns = 0;
            UINTN NumberOfRows = 0;

            Cout->QueryMode(Cout, index, &NumberOfColumns, &NumberOfRows);
            if (index == HighlightedTextModeOption)
            {
                LogHighlightedIntPair(u"Resolution: ", NumberOfColumns, NumberOfRows);
            }
            else
            {
                LogIntPair(u"Resolution: ", NumberOfColumns, NumberOfRows);
            }
        }

        EFI_INPUT_KEY Key;
        while (0 != Cin->ReadKey(Cin, &Key))
            ;

        switch (Key.ScanCode)
        {
        case 0x01:
            if (0 != HighlightedTextModeOption)
            {
                HighlightedTextModeOption--;
            }
            break;

        case 0x02:
            if (Cout->Mode->MaxMode - 1 != (INT32)HighlightedTextModeOption)
            {
                HighlightedTextModeOption++;
            }
            break;

        case 0x03:
            Cout->SetMode(Cout, HighlightedTextModeOption);
            break;

        case 0x04:
        case 0x17:
            return;

        default:
            break;
        }
    }
}

static VOID SetGraphicsModeLoop(VOID)
{
    while (1)
    {
        LogClearScreen();

        LogInt(u"Number of modes: ", Gop->Mode->MaxMode);
        LogInt(u"Current Mode: ", Gop->Mode->Mode);
        for (UINT64 index = 0; index < Gop->Mode->MaxMode; ++index)
        {
            EFI_GRAPHICS_OUTPUT_MODE_INFORMATION *GopModeInfo;
            UINTN SizeOfInfo = sizeof(*GopModeInfo);

            Gop->QueryMode(Gop, index, &SizeOfInfo, &GopModeInfo);
            if (index == HighlightedGraphicsModeOption)
            {
                LogHighlightedIntPair(u"Resolution: ", GopModeInfo->HorizontalResolution, GopModeInfo->VerticalResolution);
            }
            else
            {
                LogIntPair(u"Resolution: ", GopModeInfo->HorizontalResolution, GopModeInfo->VerticalResolution);
            }
        }

        EFI_INPUT_KEY Key;
        while (0 != Cin->ReadKey(Cin, &Key))
            ;

        switch (Key.ScanCode)
        {
        case 0x01:
            if (0 != HighlightedGraphicsModeOption)
            {
                HighlightedGraphicsModeOption--;
            }
            break;

        case 0x02:
            if (Gop->Mode->MaxMode - 1 != HighlightedGraphicsModeOption)
            {
                HighlightedGraphicsModeOption++;
            }
            break;

        case 0x03:
            Gop->SetMode(Gop, HighlightedGraphicsModeOption);
            break;

        case 0x04:
        case 0x17:
            return;

        default:
            break;
        }
    }
}

static VOID FileViewLoop(EFI_FILE_PROTOCOL *File)
{
    UINT8 Data[512];
    UINT64 DataSize = 512;

    LogClearScreen();

    File->Read(File, &DataSize, Data);
    LogBuffer(Data, DataSize);

    while (1)
    {
        EFI_INPUT_KEY Key;
        while (0 != Cin->ReadKey(Cin, &Key))
            ;

        switch (Key.ScanCode)
        {
        case 0x04:
            return;
        default:
            break;
        }
    }
}

static VOID FileExplorerLoop(VOID)
{
    EFI_FILE_PROTOCOL *NewFp;
    CHAR16 CurrentSelection[32];
    UINT64 CurrentSelectionAttribute = 0;
    EFI_FILE_INFO FileInfo;
    UINT64 FileInfoSize = 0;
    UINT64 index = 0;

    while (1)
    {
        index = 0;
        Fp->SetPosition(Fp, 0);
        FileInfoSize = sizeof(FileInfo);
        Fp->Read(Fp, &FileInfoSize, &FileInfo);

        LogClearScreen();
        while (FileInfoSize > 0)
        {
            if (HighlightedFileExplorerOption == index)
            {
                if (FileInfo.Attribute & EFI_FILE_DIRECTORY)
                {
                    LogHighlightedString(u"[DIR]   ");
                }
                else
                {
                    LogHighlightedString(u"[FILE]  ");
                }
                LogHighlightedString(FileInfo.FileName);
                LogHighlightedString(u"\r\n");

                StrcpyU16(FileInfo.FileName, CurrentSelection);
                CurrentSelectionAttribute = FileInfo.Attribute;
            }
            else
            {
                if (FileInfo.Attribute & EFI_FILE_DIRECTORY)
                {
                    LogString(u"[DIR]   ");
                }
                else
                {
                    LogString(u"[FILE]  ");
                }
                LogString(FileInfo.FileName);
                LogString(u"\r\n");
            }

            FileInfoSize = sizeof(FileInfo);
            Fp->Read(Fp, &FileInfoSize, &FileInfo);
            ++index;
        }

        EFI_INPUT_KEY Key;
        while (0 != Cin->ReadKey(Cin, &Key))
            ;

        switch (Key.ScanCode)
        {
        case 0x01:
            if (0 != HighlightedFileExplorerOption)
            {
                HighlightedFileExplorerOption--;
            }
            break;

        case 0x02:
            if (index - 1 != HighlightedFileExplorerOption)
            {
                HighlightedFileExplorerOption++;
            }
            break;

        case 0x03:
            if (CurrentSelectionAttribute & EFI_FILE_DIRECTORY)
            {
                LogString(CurrentSelection);
                Fp->Open(Fp, &NewFp, CurrentSelection, EFI_FILE_MODE_READ, 0);
                if (NULL_PTR != NewFp)
                {
                    Fp->Close(Fp);
                    Fp = NewFp;
                    HighlightedFileExplorerOption = 0;
                }
                else
                {
                    LogString(u"ERROR\r\n");
                    while (1)
                        ;
                }
            }
            else
            {
                Fp->Open(Fp, &NewFp, CurrentSelection, EFI_FILE_MODE_READ, 0);
                if (NULL_PTR != NewFp)
                {
                    FileViewLoop(NewFp);
                    NewFp->Close(NewFp);
                }
            }
            break;

        case 0x04:
        case 0x17:
            return;

        default:
            break;
        }
    }
}

static VOID LoadKernel(VOID)
{
    EFI_FILE_PROTOCOL *NewFp = NULL_PTR;

    KERNEL_ARGUMENTS *KernelArguments = NULL_PTR;
    BootServices->AllocatePool(EfiLoaderData, sizeof(*KernelArguments), (VOID **)&KernelArguments);
    BootServices->AllocatePool(EfiLoaderCode, sizeof(*KernelArguments->SystemMemory), (VOID **)&KernelArguments->SystemMemory);
    VideoAdapterInit(BootServices, &KernelArguments->VideoAdapter);
    if (E_OK != HiiLetterLoader(BootServices, &KernelArguments->CharatersBitmap))
    {
        LogString(u"Hii letter loader failed");
    }
    else
    {
        LogBuffer(KernelArguments->CharatersBitmap->Letters[u'A'].LetterBuffer, KernelArguments->CharatersBitmap->Letters[u'A'].LetterHeight * KernelArguments->CharatersBitmap->Letters[u'A'].LetterHeight);
    }

    UINT64 Rsdp = 0;
    LocateAcpi2Table(SystemTableG, &Rsdp);

    KernelArguments->RootSystemDescriptorPointer = Rsdp;

    VOID *FileBuffer = NULL_PTR;

    KernelFp->Open(KernelFp, &NewFp, u"BONTAOS", EFI_FILE_MODE_READ, 0);
    if (NULL_PTR != NewFp)
    {
        KernelFp->Close(KernelFp);
        KernelFp = NewFp;
        LogString(u"Opened BontaOS\r\n");
    }

    KernelFp->Open(KernelFp, &NewFp, u"KERNEL.BIN", EFI_FILE_MODE_READ, 0);
    if (NULL_PTR != NewFp)
    {
        KernelFp->Close(KernelFp);
        KernelFp = NewFp;
        LogString(u"Opened Kernel.bin\r\n");
    }

    BootServices->AllocatePool(EfiLoaderCode, 16 * 1024 * 1024, &FileBuffer);
    if (NULL_PTR != FileBuffer)
    {
        LogString(u"File Buffer Allocated\r\n");
    }

    UINT64 KernelSize = 16 * 1024 * 1024;
    KernelFp->Read(KernelFp, &KernelSize, FileBuffer);

    VOID *KernelEntryBuffer = NULL_PTR;
    ParseElf64(FileBuffer, &KernelEntryBuffer, AllocateMemory);
    KERNEL_ENTRY KernelEntry = (KERNEL_ENTRY)(KernelEntryBuffer);

    UINTN MemoryMapSize = 0;
    EFI_MEMORY_DESCRIPTOR *MemoryMap = NULL_PTR;
    UINTN MapKey;
    UINTN DescriptorSize;
    UINT32 DescriptorVersion;

    BootServices->GetMemoryMap(&MemoryMapSize, MemoryMap, &MapKey, &DescriptorSize, &DescriptorVersion);
    MemoryMapSize += 2 * DescriptorSize;
    BootServices->AllocatePool(EfiLoaderData, MemoryMapSize, (void **)&MemoryMap);
    BootServices->GetMemoryMap(&MemoryMapSize, MemoryMap, &MapKey, &DescriptorSize, &DescriptorVersion);

    KernelArguments->SystemMemory->MemoryMapSize = MemoryMapSize;
    KernelArguments->SystemMemory->MemoryMap = MemoryMap;
    KernelArguments->SystemMemory->MapKey = MapKey;
    KernelArguments->SystemMemory->DescriptorSize = DescriptorSize;
    KernelArguments->SystemMemory->DescriptorVersion = DescriptorVersion;

    for (EFI_MEMORY_DESCRIPTOR *MapEntry = MemoryMap; (UINT64)MapEntry < (UINT64)((UINT8 *)MemoryMap + MemoryMapSize); MapEntry = (EFI_MEMORY_DESCRIPTOR *)((UINT8 *)MapEntry + DescriptorSize))
    {
        if (MapEntry->Type == EfiConventionalMemory)
        {
            LogHex(u"PS, VS, NoP, T, A: ", MapEntry->PhysicalStart);
            LogHex(u" ", MapEntry->VirtualStart);
            LogHex(u" ", MapEntry->NumberOfPages);
            LogHex(u" ", MapEntry->Type);
            LogHex(u" ", MapEntry->Attribute);
            LogString(u"\r\n");
        }
    }

    EFI_INPUT_KEY Key;
    while (0 != Cin->ReadKey(Cin, &Key))
        ;

    // LogString(u"Calling kernel entry\r\n");
    // LogBuffer(Buffer, KernelSize);
    BootServices->ExitBootServices(Handle, MapKey);
    KernelEntry(KernelArguments);

    LogString(u"Massive fuck up");

    while (0 != Cin->ReadKey(Cin, &Key))
        ;

    switch (Key.ScanCode)
    {
    case 0x04:
    case 0x17:
        return;

    default:
        break;
    }
}

static STATUS API AllocateMemory(OUT VOID **Buffer, IN CONST UINT64 Size)
{
    if (EFI_SUCCESS != BootServices->AllocatePool(EfiLoaderData, Size, Buffer))
    {
        return E_NOT_OK;
    }

    return E_OK;
}
