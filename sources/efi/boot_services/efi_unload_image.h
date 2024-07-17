#ifndef _EFI_UNLOAD_IMAGE_H_
#define _EFI_UNLOAD_IMAGE_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_IMAGE_UNLOAD)(
    IN EFI_HANDLE ImageHandle);

#endif /* _EFI_UNLOAD_IMAGE_H_ */
