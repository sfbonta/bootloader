#ifndef _EFI_SET_VARIABLE_NAME_H_
#define _EFI_SET_VARIABLE_NAME_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_SET_VARIABLE)(
    IN CHAR16 *VariableName,
    IN EFI_GUID *VendorGuid,
    IN UINT32 Attributes,
    IN UINTN DataSize,
    IN VOID *Data);

#endif /* _EFI_SET_VARIABLE_NAME_H_ */
