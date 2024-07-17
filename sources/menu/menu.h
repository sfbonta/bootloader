#ifndef _MENU_H_
#define _MENU_H_

#include "efi_types.h"
#include "efi_system_table.h"

VOID MenuInit(EFI_SYSTEM_TABLE* SystemTable, EFI_HANDLE ImageHandle);

VOID MenuLoop(VOID);

#endif /* _MENU_H_ */
