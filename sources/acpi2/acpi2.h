#ifndef _ACPI2_H_
#define _ACPI2_H_

#include "platform_types.h"
#include "efi_system_table.h"

STATUS LocateAcpi2Table(IN CONST EFI_SYSTEM_TABLE* SystemTable, OUT UINT64* RootSystemDescriptionPointer);

#endif /* _ACPI2_H_ */
