#ifndef _EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES_H_
#define _EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES)(
    IN EFI_HANDLE Handle,
    ...);

#endif /* _EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES_H_ */
