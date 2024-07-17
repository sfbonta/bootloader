#ifndef _VIDEO_ADAPTER_H_
#define _VIDEO_ADAPTER_H_

#include "video_adapter_types.h"
#include "efi_boot_services.h"

STATUS VideoAdapterInit(IN EFI_BOOT_SERVICES *BootServices, OUT VIDEO_ADAPTER **VideoAdapter);

#endif /* _VIDEO_ADAPTER_H_ */
