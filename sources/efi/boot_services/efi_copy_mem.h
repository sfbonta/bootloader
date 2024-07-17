#ifndef _EFI_COPY_MEM_H_
#define _EFI_COPY_MEM_H_

#include "efi_types.h"

typedef VOID(EFI_API *EFI_COPY_MEM)(
    IN VOID *Destination,
    IN VOID *Source,
    IN UINTN Length);

#endif /* _EFI_COPY_MEM_H_ */
