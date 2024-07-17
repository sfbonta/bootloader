#ifndef _EFI_SET_TIMER_H_
#define _EFI_SET_TIMER_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_SET_TIMER)(
    IN EFI_EVENT Event,
    IN EFI_TIMER_DELAY Type,
    IN UINT64 TriggerTime);

#endif /* _EFI_SET_TIMER_H_ */
