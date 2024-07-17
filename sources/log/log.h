#ifndef _LOG_H_
#define _LOG_H_

#include "efi_system_table.h"
#include "platform_types.h"

STATUS EFI_API LogInitialize(IN CONST EFI_SYSTEM_TABLE *SystemTable);

STATUS LogClearScreen(VOID);

STATUS EFI_API LogString(IN CONST CHAR16 *OutputString);

STATUS EFI_API LogHighlightedString(IN CONST CHAR16 *OutputString);

STATUS EFI_API LogInt(IN CONST CHAR16 *Info, INT64 Value);

STATUS EFI_API LogIntPair(IN CONST CHAR16 *Info, INT64 FirstValue, INT64 SecondValue);

STATUS EFI_API LogHighlightedIntPair(IN CONST CHAR16 *Info, INT64 FirstValue, INT64 SecondValue);

STATUS EFI_API LogHex(IN CONST CHAR16 *Info, UINT64 Value);

STATUS EFI_API LogBuffer(IN CONST UINT8* Buffer, UINT64 BufferSize);

#endif /* _LOG_H_ */
