#ifndef _EFI_GET_NEXT_VARIABLE_NAME_H_
#define _EFI_GET_NEXT_VARIABLE_NAME_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_GET_NEXT_VARIABLE_NAME)(
    IN OUT UINTN *VariableNameSize,
    IN OUT CHAR16 *VariableName,
    IN OUT EFI_GUID *VendorGuid);

#endif /* _EFI_GET_NEXT_VARIABLE_NAME_H_ */
