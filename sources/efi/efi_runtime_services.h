#ifndef _EFI_RUNTIME_SERVICES_H_
#define _EFI_RUNTIME_SERVICES_H_

#include "efi_types.h"
#include "efi_table_header.h"
#include "runtime_services/efi_get_variable.h"
#include "runtime_services/efi_get_next_variable_name.h"
#include "runtime_services/efi_set_variable.h"
#include "runtime_services/efi_query_variable_info.h"
#include "runtime_services/efi_get_time.h"
#include "runtime_services/efi_set_time.h"
#include "runtime_services/efi_get_wakeup_time.h"
#include "runtime_services/efi_set_wakeup_time.h"
#include "runtime_services/efi_set_virtual_map.h"
#include "runtime_services/efi_convert_pointer.h"
#include "runtime_services/efi_reset_system.h"
#include "runtime_services/efi_get_next_high_monotonic_count.h"
#include "runtime_services/efi_update_capsule.h"
#include "runtime_services/efi_query_capsule_capabilities.h"

typedef struct _EFI_RUNTIME_SERVICES
{
    EFI_TABLE_HEADER Header;

    // Time Services
    EFI_GET_TIME GetTime;
    EFI_SET_TIME SetTime;
    EFI_GET_WAKEUP_TIME GetWakeupTime;
    EFI_SET_WAKEUP_TIME SetWakeupTime;

    // Virtual Memory Services
    EFI_SET_VIRTUAL_MAP SetVirtualMap;
    EFI_CONVERT_POINTER ConvertPointer;

    // Variable Services
    EFI_GET_VARIABLE GetVariable;
    EFI_GET_NEXT_VARIABLE_NAME GetNextVariableName;
    EFI_SET_VARIABLE SetVariable;

    // Miscellaneous Services
    EFI_GET_NEXT_HIGH_MONOTONIC_COUNT GetNextHighMonotonicCount;
    EFI_RESET_SYSTEM ResetSystem;

    // Capsule Services
    EFI_UPDATE_CAPSULE UpdateCapsule;
    EFI_QUERY_CAPSULE_CAPABILITIES QueryCapsuleCapabilities;

    // Miscellaneous
    EFI_QUERY_VARIABLE_INFO QueryVariableInfo;
} EFI_RUNTIME_SERVICES;

#endif /* __EFI_RUNTIME_SERVICES_H_ */
