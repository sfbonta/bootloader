#ifndef _EFI_START_IMAGE_H_
#define _EFI_START_IMAGE_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_IMAGE_START)(
    IN EFI_HANDLE ImageHandle,
    OUT UINTN *ExitDataSize,
    OUT OPTIONAL CHAR16 **ExitData);

#endif /* _EFI_START_IMAGE_H_ */
