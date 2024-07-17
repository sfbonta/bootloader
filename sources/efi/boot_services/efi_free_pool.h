#ifndef _EFI_FREE_POOL_H_
#define _EFI_FREE_POOL_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_FREE_POOL)(
    IN VOID *Buffer);

#endif /* _EFI_FREE_POOL_H_ */
