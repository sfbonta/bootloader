#ifndef _EFI_SYSTEM_TABLE_H_
#define _EFI_SYSTEM_TABLE_H_

#include "efi_types.h"
#include "efi_table_header.h"
#include "protocols/efi_simple_text_input_protocol.h"
#include "protocols/efi_simple_text_output_protocol.h"
#include "efi_runtime_services.h"
#include "efi_boot_services.h"
#include "efi_configuration_table.h"

typedef struct _EFI_SYSTEM_TABLE
{
    EFI_TABLE_HEADER Header;
    CHAR16 *FirmwareVendor;
    UINT32 FirmwareRevision;
    EFI_HANDLE ConsoleInHandle;
    EFI_SIMPLE_TEXT_INPUT_PROTOCOL *ConsoleIn;
    EFI_HANDLE ConsoleOutHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *ConsoleOut;
    EFI_HANDLE StandardErrorHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *StandardError;
    EFI_RUNTIME_SERVICES *RuntimeServices;
    EFI_BOOT_SERVICES *BootServices;
    UINTN NumberOfTableEntries;
    EFI_CONFIGURATION_TABLE *ConfigurationTable;
} EFI_SYSTEM_TABLE;

#endif /* _EFI_H_ */
