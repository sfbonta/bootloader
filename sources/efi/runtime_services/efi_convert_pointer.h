#ifndef _EFI_CONVERT_POINTER_H_
#define _EFI_CONVERT_POINTER_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_CONVERT_POINTER)(
    IN UINTN DebugDisposition,
    IN VOID **Address);

#endif /* _EFI_CONVERT_POINTER_H_ */
