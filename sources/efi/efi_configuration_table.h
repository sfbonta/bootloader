#ifndef _EFI_CONFIGURATION_TABLE_H_
#define _EFI_CONFIGURATION_TABLE_H_

#include "efi_types.h"

typedef struct _EFI_CONFIGURATION_TABLE
{
    EFI_GUID VendorGuid;
    VOID *VendorTable;
} EFI_CONFIGURATION_TABLE;

#endif /* _EFI_CONFIGURATION_TABLE_H_ */
