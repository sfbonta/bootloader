#ifndef _EFI_RESTORE_TPL_H_
#define _EFI_RESTORE_TPL_H_

#include "efi_types.h"

typedef VOID(EFI_API *EFI_RESTORE_TPL)(
    IN EFI_TPL OldTpl);

#endif /* _EFI_RESTORE_TPL_H_ */
