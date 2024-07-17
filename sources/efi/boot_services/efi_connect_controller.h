#ifndef _EFI_CONNECT_CONTROLLER_H_
#define _EFI_CONNECT_CONTROLLER_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_CONNECT_CONTROLLER)(
    IN EFI_HANDLE ControllerHandle,
    IN EFI_HANDLE *DriverImageHandle OPTIONAL,
    IN EFI_DEVICE_PATH_PROTOCOL *RemainingDevicePath OPTIONAL,
    IN BOOLEAN Recursive);

#endif /* _EFI_CONNECT_CONTROLLER_H_ */
