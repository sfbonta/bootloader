#ifndef _EFI_SET_MEM_H_
#define _EFI_SET_MEM_H_

#include "efi_types.h"

typedef VOID(EFI_API *EFI_SET_MEM)(
    IN VOID *Buffer,
    IN UINTN Size,
    IN UINT8 Value);

#endif /* _EFI_SET_MEM_H_ */
