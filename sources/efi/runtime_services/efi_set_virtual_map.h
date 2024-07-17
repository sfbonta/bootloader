#ifndef _EFI_SET_VIRTUAL_MAP_H_
#define _EFI_SET_VIRTUAL_MAP_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_SET_VIRTUAL_MAP)(
    IN UINTN MemoryMapSize,
    IN UINTN DescriptorSize,
    IN UINT32 DescriptorVersion,
    IN EFI_MEMORY_DESCRIPTOR *VirtualMap);

#endif /* _EFI_SET_VIRTUAL_MAP_H_ */
