#include "acpi2.h"
#include "utils.h"

#define EFI_ACPI_20_TABLE_GUID                             \
    {                                                      \
        0x8868e871, 0xe4f1, 0x11d3,                        \
        {                                                  \
            0xbc, 0x22, 0x00, 0x80, 0xc7, 0x3c, 0x88, 0x81 \
        }                                                  \
    }

STATUS LocateAcpi2Table(IN CONST EFI_SYSTEM_TABLE* SystemTable, OUT UINT64* RootSystemDescriptionPointer)
{
    for (UINT64 i = 0; i < SystemTable->NumberOfTableEntries ; ++i)
    {
        EFI_GUID Acpi2Guid = EFI_ACPI_20_TABLE_GUID;
        if (0 == MemoryCompare(&SystemTable->ConfigurationTable[i].VendorGuid, &Acpi2Guid, sizeof(Acpi2Guid)))
        {
            *RootSystemDescriptionPointer = (UINT64)SystemTable->ConfigurationTable[i].VendorTable;
            return E_OK;
        }
    }

    return E_NOT_OK;
}
