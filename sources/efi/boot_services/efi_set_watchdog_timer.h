#ifndef _EFI_SET_WATCHDOG_TIMER_H_
#define _EFI_SET_WATCHDOG_TIMER_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_SET_WATCHDOG_TIMER)(
    IN UINTN Timeout,
    IN UINT64 WatchdogCode,
    IN UINTN DataSize,
    IN OPTIONAL CHAR16 *WatchdogData);

#endif /* _EFI_SET_WATCHDOG_TIMER_H_ */
