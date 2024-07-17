#ifndef _EFI_RESET_SYSTEM_H_
#define _EFI_RESET_SYSTEM_H_

#include "efi_types.h"

typedef VOID(EFI_API *EFI_RESET_SYSTEM)(
    IN EFI_RESET_TYPE ResetType,
    IN EFI_STATUS ResetStatus,
    IN UINTN DataSize,
    IN OPTIONAL VOID *ResetData);

#endif /* _EFI_RESET_SYSTEM_H_ */
