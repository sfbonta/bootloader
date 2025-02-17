#ifndef _EFI_GET_NEXT_MONOTONIC_COUNT_H_
#define _EFI_GET_NEXT_MONOTONIC_COUNT_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_GET_NEXT_MONOTONIC_COUNT)(
    OUT UINT64 *Count);

#endif /* _EFI_GET_NEXT_MONOTONIC_COUNT_H_ */
