#ifndef _EFI_LOCATE_HANDLE_H_
#define _EFI_LOCATE_HANDLE_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_LOCATE_HANDLE)(
    IN EFI_LOCATE_SEARCH_TYPE SearchType,
    IN OPTIONAL EFI_GUID *Protocol,
    IN OPTIONAL VOID *SearchKey,
    IN OUT UINTN *BufferSize,
    OUT EFI_HANDLE *Buffer);

#endif /* _EFI_LOCATE_HANDLE_H_ */
