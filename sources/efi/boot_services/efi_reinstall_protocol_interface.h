#ifndef _EFI_REINSTALL_PROTOCOL_H_
#define _EFI_REINSTALL_PROTOCOL_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_REINSTALL_PROTOCOL_INTERFACE)(
    IN EFI_HANDLE Handle,
    IN EFI_GUID *Protocol,
    IN VOID *OldInterface,
    IN VOID *NewInterface);

#endif /* _EFI_REINSTALL_PROTOCOL_H_ */
