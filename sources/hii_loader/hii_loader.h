#ifndef _HII_LOADER_H_
#define _HII_LOADER_H_

#include "hii_loader_types.h"
#include "efi_boot_services.h"

STATUS HiiLetterLoader(CONST IN EFI_BOOT_SERVICES* BootServices, OUT HII_CHARACTERS **Charaters);

#endif /* _HII_LOADER_H_ */
