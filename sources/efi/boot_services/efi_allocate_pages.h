#ifndef _EFI_ALLOCATE_PAGES_H_
#define _EFI_ALLOCATE_PAGES_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_ALLOCATE_PAGES)(
    IN EFI_ALLOCATE_TYPE Type,
    IN EFI_MEMORY_TYPE MemoryType,
    IN UINTN Pages,
    IN OUT EFI_PHYSICAL_ADDRESS *Memory);

#endif /* _EFI_ALLOCATE_PAGES_H_ */
