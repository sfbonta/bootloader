#ifndef _EFI_QUERY_VARIABLE_INFO_H_
#define _EFI_QUERY_VARIABLE_INFO_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_QUERY_VARIABLE_INFO)(
    IN UINT32 Attributes,
    OUT UINT64 *MaximumVariableStorageSize,
    OUT UINT64 *RemainingVariableStorageSize,
    OUT UINT64 *MaximumVariableSize);

#endif /* _EFI_QUERY_VARIABLE_INFO_H_ */
