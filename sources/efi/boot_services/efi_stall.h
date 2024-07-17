#ifndef _EFI_STALL_H_
#define _EFI_STALL_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_STALL)(
    IN UINTN Microseconds);

#endif /* _EFI_STALL_H_ */
