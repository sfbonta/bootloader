#ifndef _EFI_GET_WAKEUP_TIME_H_
#define _EFI_GET_WAKEUP_TIME_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_GET_WAKEUP_TIME)(
    OUT BOOLEAN *Enabled,
    OUT BOOLEAN *Pending,
    OUT EFI_TIME *Time);

#endif /* _EFI_GET_WAKEUP_TIME_H_ */
