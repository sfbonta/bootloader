#include "efi_system_table.h"
#include "log.h"
#include "menu.h"

EFI_STATUS EFI_API EfiMain(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
    MenuInit(SystemTable, ImageHandle);

    while (1)
    {
        MenuLoop();
    }
    return 0;
}
