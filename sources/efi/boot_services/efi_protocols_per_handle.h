#ifndef _EFI_PROTOCOLS_PER_HANDLE_H_
#define _EFI_PROTOCOLS_PER_HANDLE_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_PROTOCOLS_PER_HANDLE)(
    IN EFI_HANDLE Handle,
    OUT EFI_GUID ***ProtocolBuffer,
    OUT UINTN *ProtocolBufferCount);

#endif /* _EFI_PROTOCOLS_PER_HANDLE_H_ */
