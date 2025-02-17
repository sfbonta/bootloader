#ifndef _EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_H_
#define _EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_H_

#include "efi_types.h"
#include "efi_file_protocol.h"

#define EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID               \
    {                                                      \
        0x0964e5b22, 0x6459, 0x11d2,                       \
        {                                                  \
            0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b \
        }                                                  \
    }

typedef struct _EFI_SIMPLE_FILE_SYSTEM_PROTOCOL EFI_SIMPLE_FILE_SYSTEM_PROTOCOL;

typedef EFI_STATUS(EFI_API *EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_OPEN_VOLUME)(
    IN EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *This,
    OUT EFI_FILE_PROTOCOL **Root);

typedef struct _EFI_SIMPLE_FILE_SYSTEM_PROTOCOL
{
    UINT64 Revision;
    EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_OPEN_VOLUME OpenVolume;
} EFI_SIMPLE_FILE_SYSTEM_PROTOCOL;

#endif /* _EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_H_ */
