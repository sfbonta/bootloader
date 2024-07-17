#ifndef _EFI_QUERY_CAPSULE_CAPABILITES_H_
#define _EFI_QUERY_CAPSULE_CAPABILITES_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_QUERY_CAPSULE_CAPABILITIES)(
    IN EFI_CAPSULE_HEADER **CapsuleHeaderArray,
    IN UINTN CapsuleCount,
    OUT UINT64 *MaximumCapsuleSize,
    OUT EFI_RESET_TYPE *ResetType);

#endif /* _EFI_QUERY_CAPSULE_CAPABILITES_H_ */
