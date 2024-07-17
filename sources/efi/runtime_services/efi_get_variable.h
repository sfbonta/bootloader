#ifndef _EFI_GET_VARIABLE_H_
#define _EFI_GET_VARIABLE_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_GET_VARIABLE)(
    IN CHAR16 *VariableName,
    IN EFI_GUID *VendorGuid,
    OUT OPTIONAL UINT32 *Attributes,
    IN OUT UINTN *DataSize,
    OUT OPTIONAL VOID *Data);

#endif /* _EFI_GET_VARIABLE_H_ */
