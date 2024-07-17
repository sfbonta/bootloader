#ifndef _EFI_LOAD_IMAGE_H_
#define _EFI_LOAD_IMAGE_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_LOAD_IMAGE)(
    IN BOOLEAN BootPolicy,
    IN EFI_HANDLE ParentImageHandle,
    IN OPTIONAL EFI_DEVICE_PATH_PROTOCOL *DevicePath,
    IN OPTIONAL VOID *SourceBuffer,
    IN UINTN SourceSize,
    OUT EFI_HANDLE *ImageHandle);

#endif /* _EFI_LOAD_IMAGE_H_ */
