#ifndef _EFI_FREE_PAGES_H_
#define _EFI_FREE_PAGES_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_FREE_PAGES)(
    IN EFI_PHYSICAL_ADDRESS Memory,
    IN UINTN Pages);

#endif /* _EFI_FREE_PAGES_H_ */
