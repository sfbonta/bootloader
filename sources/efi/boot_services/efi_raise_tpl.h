#ifndef _EFI_RAISE_TPL_H_
#define _EFI_RAISE_TPL_H_

#include "efi_types.h"

typedef EFI_TPL(EFI_API *EFI_RAISE_TPL)(
    IN EFI_TPL NewTpl);

#endif /* _EFI_RAISE_TPL_H_ */
