#ifndef _EFI_LOCATE_PROTOCOL_H_
#define _EFI_LOCATE_PROTOCOL_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_LOCATE_PROTOCOL)(
    IN EFI_GUID *Protocol,
    IN OPTIONAL VOID *Registration,
    OUT VOID **Interface);

#endif /* _EFI_LOCATE_PROTOCOL_H_ */
