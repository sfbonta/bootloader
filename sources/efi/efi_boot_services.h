#ifndef _EFI_BOOT_SERVICES_H_
#define _EFI_BOOT_SERVICES_H_

#include "efi_types.h"
#include "efi_table_header.h"
#include "boot_services/efi_create_event.h"
#include "boot_services/efi_create_event_ex.h"
#include "boot_services/efi_close_event.h"
#include "boot_services/efi_signal_event.h"
#include "boot_services/efi_wait_for_event.h"
#include "boot_services/efi_check_event.h"
#include "boot_services/efi_set_timer.h"
#include "boot_services/efi_raise_tpl.h"
#include "boot_services/efi_restore_tpl.h"
#include "boot_services/efi_allocate_pages.h"
#include "boot_services/efi_free_pages.h"
#include "boot_services/efi_get_memory_map.h"
#include "boot_services/efi_allocate_pool.h"
#include "boot_services/efi_free_pool.h"
#include "boot_services/efi_install_protocol_interface.h"
#include "boot_services/efi_uninstall_protocol_interface.h"
#include "boot_services/efi_reinstall_protocol_interface.h"
#include "boot_services/efi_register_protocol_notify.h"
#include "boot_services/efi_locate_handle.h"
#include "boot_services/efi_handle_protocol.h"
#include "boot_services/efi_locate_device_path.h"
#include "boot_services/efi_open_protocol.h"
#include "boot_services/efi_close_protocol.h"
#include "boot_services/efi_open_protocol_information.h"
#include "boot_services/efi_connect_controller.h"
#include "boot_services/efi_disconect_controller.h"
#include "boot_services/efi_protocols_per_handle.h"
#include "boot_services/efi_locate_handle_buffer.h"
#include "boot_services/efi_locate_protocol.h"
#include "boot_services/efi_install_multiple_protocol_interfaces.h"
#include "boot_services/efi_uninstall_multiple_protocol_interfaces.h"
#include "boot_services/efi_load_image.h"
#include "boot_services/efi_start_image.h"
#include "boot_services/efi_unload_image.h"
#include "boot_services/efi_exit.h"
#include "boot_services/efi_exit_boot_services.h"
#include "boot_services/efi_set_watchdog_timer.h"
#include "boot_services/efi_stall.h"
#include "boot_services/efi_copy_mem.h"
#include "boot_services/efi_set_mem.h"
#include "boot_services/efi_get_next_monotonic_count.h"
#include "boot_services/efi_install_configuration_table.h"
#include "boot_services/efi_calculate_crc32.h"

typedef struct _EFI_BOOT_SERVICES
{
    EFI_TABLE_HEADER Header;

    // Task Priority Services
    EFI_RAISE_TPL RaiseTpl;
    EFI_RESTORE_TPL RestoreTpl;

    // Memory Services
    EFI_ALLOCATE_PAGES AllocatePages;
    EFI_FREE_PAGES FreePages;
    EFI_GET_MEMORY_MAP GetMemoryMap;
    EFI_ALLOCATE_POOL AllocatePool;
    EFI_FREE_POOL FreePool;

    // Event and Timer Services
    EFI_CREATE_EVENT CreateEvent;
    EFI_SET_TIMER SetTimer;
    EFI_WAIT_FOR_EVENT WaitForEvent;
    EFI_SIGNAL_EVENT SignalEvent;
    EFI_CLOSE_EVENT CloseEvent;
    EFI_CHECK_EVENT CheckEvent;

    // Protocol Handler Services
    EFI_INSTALL_PROTOCOL_INTERFACE InstallProtocolInterface;
    EFI_REINSTALL_PROTOCOL_INTERFACE ReinstallProtocolInterface;
    EFI_UNINSTALL_PROTOCOL_INTERFACE UninstallProtocolInterface;
    EFI_HANDLE_PROTOCOL HandleProtocol;
    VOID *Reserved;
    EFI_REGISTER_PROTOCOL_NOTIFY RegisterProtocolNotify;
    EFI_LOCATE_HANDLE LocateHandle;
    EFI_LOCATE_DEVICE_PATH LocateDevicePath;
    EFI_INSTALL_CONFIGURATION_TABLE InstallConfigurationTable;

    // Image Services
    EFI_LOAD_IMAGE LoadImage;
    EFI_IMAGE_START StartImage;
    EFI_EXIT Exit;
    EFI_IMAGE_UNLOAD UnloadImage;
    EFI_EXIT_BOOT_SERVICES ExitBootServices;

    // Miscellaneous Services
    EFI_GET_NEXT_MONOTONIC_COUNT GetNextMonotonicCount;
    EFI_STALL Stall;
    EFI_SET_WATCHDOG_TIMER SetWatchdogTimer;

    // Driver Support Services
    EFI_CONNECT_CONTROLLER ConnectController;
    EFI_DISCONNECT_CONTROLLER DisconnectController;

    // Open and Close Protocol Services
    EFI_OPEN_PROTOCOL OpenProtocol;
    EFI_CLOSE_PROTOCOL CloseProtocol;
    EFI_OPEN_PROTOCOL_INFORMATION OpenProtocolInformation;

    // Library Services
    EFI_PROTOCOLS_PER_HANDLE ProtocolsPerHandle;
    EFI_LOCATE_HANDLE_BUFFER LocateHandleBuffer;
    EFI_LOCATE_PROTOCOL LocateProtocol;
    EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES InstallMultipleProtocolInterfaces;
    EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES UninstallMultipleProtocolInterfaces;

    // 32-bit CRC Services
    EFI_CALCULATE_CRC32 CalculateCrc32;

    // Miscellaneous Services
    EFI_COPY_MEM CopyMem;
    EFI_SET_MEM SetMem;
    EFI_CREATE_EVENT_EX CreateEventEx;

} EFI_BOOT_SERVICES;

#endif /* _EFI_BOOT_SERVICES_H_ */
