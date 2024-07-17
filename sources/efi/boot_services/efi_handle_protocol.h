#ifndef _EFI_HANDLE_PROTOCOL_H_
#define _EFI_HANDLE_PROTOCOL_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_HANDLE_PROTOCOL)(
    IN EFI_HANDLE Handle,
    IN EFI_GUID *Protocol,
    OUT VOID **Interface);

#endif /* _EFI_HANDLE_PROTOCOL_H_ */
