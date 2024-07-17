#ifndef _EFI_CLOSE_EVENT_H_
#define _EFI_CLOSE_EVENT_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_CLOSE_EVENT)(
    IN EFI_EVENT Event);

#endif /* _EFI_CLOSE_EVENT_H_ */
