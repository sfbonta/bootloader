#ifndef _EFI_SIGNAL_EVENT_H_
#define _EFI_SIGNAL_EVENT_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_SIGNAL_EVENT)(
    IN EFI_EVENT Event);

#endif /* _EFI_SIGNAL_EVENT_H_ */
