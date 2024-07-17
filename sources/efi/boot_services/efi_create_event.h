#ifndef _EFI_CREATE_EVENT_H_
#define _EFI_CREATE_EVENT_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_CREATE_EVENT)(
    IN UINT32 Type,
    IN EFI_TPL NotifyTpl,
    IN OPTIONAL EFI_EVENT_NOTIFY NotifyFunction,
    IN OPTIONAL VOID *NotifyContext,
    OUT EFI_EVENT *Event);

#endif /* _EFI_CREATE_EVENT_H_ */
