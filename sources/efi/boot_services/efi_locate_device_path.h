#ifndef _EFI_LOCATE_DEVICE_PATH_H_
#define _EFI_LOCATE_DEVICE_PATH_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_LOCATE_DEVICE_PATH)(
    IN EFI_GUID *Protocol,
    IN OUT EFI_DEVICE_PATH_PROTOCOL **DevicePath,
    OUT EFI_HANDLE *Device);

#endif /* _EFI_LOCATE_DEVICE_PATH_H_ */
