#ifndef _EFI_TABLE_HEADER_H_
#define _EFI_TABLE_HEADER_H_

#include "efi_types.h"

typedef struct _EFI_TABLE_HEADER
{
    UINT64 Signature;
    UINT32 Revision;
    UINT32 HeaderSize;
    UINT32 CRC32;
    UINT32 Reserved;
} EFI_TABLE_HEADER;

#endif /* _EFI_TABLE_HEADER_H_ */
