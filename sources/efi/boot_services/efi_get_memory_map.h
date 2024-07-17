#ifndef _EFI_GET_MEMORY_MAP_H_
#define _EFI_GET_MEMORY_MAP_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_GET_MEMORY_MAP)(
    IN OUT UINTN *MemoryMapSize,
    OUT EFI_MEMORY_DESCRIPTOR *MemoryMap,
    OUT UINTN *MapKey,
    OUT UINTN *DescriptorSize,
    OUT UINT32 *DescriptorVersion);

#endif /* _EFI_GET_MEMORY_MAP_H_ */
