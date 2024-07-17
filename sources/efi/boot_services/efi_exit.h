#ifndef _EFI_EXIT_H_
#define _EFI_EXIT_H_

#include "efi_types.h"

typedef EFI_STATUS(EFI_API *EFI_EXIT)(
    IN EFI_HANDLE ImageHandle,
    IN EFI_STATUS ExitStatus,
    IN UINTN ExitDataSize,
    IN OPTIONAL CHAR16 *ExitData);

#endif /* _EFI_EXIT_H_ */
