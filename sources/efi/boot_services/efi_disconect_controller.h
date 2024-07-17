#ifndef _EFI_DISCONNECT_CONTROLLER_H_
#define _EFI_DISCONNECT_CONTROLLER_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_DISCONNECT_CONTROLLER)(
    IN EFI_HANDLE ControllerHandle,
    IN OPTIONAL EFI_HANDLE DriverImageHandle,
    IN OPTIONAL EFI_HANDLE ChildHandle);

#endif /* _EFI_DISCONNECT_CONTROLLER_H_ */
