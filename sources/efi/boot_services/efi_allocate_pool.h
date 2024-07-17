#ifndef _EFI_ALLOCATE_POOL_H_
#define _EFI_ALLOCATE_POOL_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_ALLOCATE_POOL)(
    IN EFI_MEMORY_TYPE PoolType,
    IN UINTN Size,
    OUT VOID **Buffer);

#endif /* _EFI_ALLOCATE_POOL_H_ */
