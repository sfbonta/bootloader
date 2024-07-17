#ifndef _EFI_GET_TIME_H_
#define _EFI_GET_TIME_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_GET_TIME)(
    OUT EFI_TIME *Time,
    OUT OPTIONAL EFI_TIME_CAPABILITIES *Capabilities);

#endif /* _EFI_GET_TIME_H_ */
