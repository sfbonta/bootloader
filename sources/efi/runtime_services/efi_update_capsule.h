#ifndef _EFI_UPDATE_CAPSULE_H_
#define _EFI_UPDATE_CAPSULE_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_UPDATE_CAPSULE)(
    IN EFI_CAPSULE_HEADER **CapsuleHeaderArray,
    IN UINTN CapsuleCount,
    IN OPTIONAL EFI_PHYSICAL_ADDRESS ScatterGatherList);

#endif /* _EFI_UPDATE_CAPSULE_H_ */
