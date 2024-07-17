#ifndef _EFI_REGISTER_PROTOCOL_NOTIFY_H_
#define _EFI_REGISTER_PROTOCOL_NOTIFY_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_REGISTER_PROTOCOL_NOTIFY)(
    IN EFI_GUID *Protocol,
    IN EFI_EVENT Event,
    OUT VOID **Registration);

#endif /* _EFI_REGISTER_PROTOCOL_NOTIFY_H_ */
