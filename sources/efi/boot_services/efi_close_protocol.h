#ifndef _EFI_CLOSE_PROTOCOL_H_
#define _EFI_CLOSE_PROTOCOL_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_CLOSE_PROTOCOL)(
    IN EFI_HANDLE Handle,
    IN EFI_GUID *Protocol,
    IN EFI_HANDLE AgentHandle,
    IN EFI_HANDLE ControllerHandle);

#endif /* _EFI_CLOSE_PROTOCOL_H_ */
