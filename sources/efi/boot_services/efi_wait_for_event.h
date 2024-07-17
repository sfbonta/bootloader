#ifndef _EFI_WAIT_FOR_EVENT_H_
#define _EFI_WAIT_FOR_EVENT_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_WAIT_FOR_EVENT)(
    IN UINTN NumberOfEvents,
    IN EFI_EVENT *Event,
    OUT UINTN *Index);

#endif /* _EFI_WAIT_FOR_EVENT_H_ */
