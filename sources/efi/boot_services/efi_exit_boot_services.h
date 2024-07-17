#ifndef _EFI_EXIT_BOOT_SERVICES_H_
#define _EFI_EXIT_BOOT_SERVICES_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_EXIT_BOOT_SERVICES)(
    IN EFI_HANDLE ImageHandle,
    IN UINTN MapKey);

#endif /* _EFI_EXIT_BOOT_SERVICES_H_ */
