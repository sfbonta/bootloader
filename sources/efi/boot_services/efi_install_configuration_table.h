#ifndef _EFI_INSTALL_CONFIGURATION_TABLE_H_
#define _EFI_INSTALL_CONFIGURATION_TABLE_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_INSTALL_CONFIGURATION_TABLE)(
    IN EFI_GUID *Guid,
    IN VOID *Table);

#endif /* _EFI_INSTALL_CONFIGURATION_TABLE_H_ */
