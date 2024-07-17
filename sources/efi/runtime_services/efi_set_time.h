#ifndef _EFI_SET_TIME_H_
#define _EFI_SET_TIME_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_SET_TIME)(
    IN EFI_TIME *Time);

#endif /* _EFI_SET_TIME_H_ */
