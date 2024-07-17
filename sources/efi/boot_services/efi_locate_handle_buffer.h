#ifndef _EFI_LOCATE_HANDLE_BUFFER_H_
#define _EFI_LOCATE_HANDLE_BUFFER_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_LOCATE_HANDLE_BUFFER)(
    IN EFI_LOCATE_SEARCH_TYPE SearchType,
    IN OPTIONAL EFI_GUID *Protocol,
    IN OPTIONAL VOID *SearchKey,
    OUT UINTN *NoHandles,
    OUT EFI_HANDLE **Buffer);

#endif /* _EFI_LOCATE_HANDLE_BUFFER_H_ */
