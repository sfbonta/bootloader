#ifndef _EFI_CALCULATE_CRC32_H_
#define _EFI_CALCULATE_CRC32_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_CALCULATE_CRC32)(
    IN VOID *Data,
    IN UINTN DataSize,
    OUT UINT32 *Crc32);

#endif /* _EFI_CALCULATE_CRC32_H_ */
