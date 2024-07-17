#include "video_adapter.h"

#include "protocols/efi_graphics_output_protocol.h"
#include "efi_status_defines.h"
#include "log.h"

STATUS VideoAdapterInit(IN EFI_BOOT_SERVICES *BootServices, OUT VIDEO_ADAPTER **VideoAdapter)
{
    STATUS Status = E_OK;
    EFI_GRAPHICS_OUTPUT_PROTOCOL *Gop = NULL_PTR;
    EFI_GUID GraphicsOutputProtocolGuid = EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID;

    if (EFI_SUCCESS != BootServices->LocateProtocol(&GraphicsOutputProtocolGuid, NULL_PTR, (VOID **)&Gop))
    {
        Status = E_NOT_OK;
        LogString(u"Can not open GOP protocol\r\n");
        goto Cleanup;
    }

    BootServices->AllocatePool(EfiLoaderData, sizeof(**VideoAdapter), (VOID **)VideoAdapter);
    if (NULL_PTR == VideoAdapter)
    {
        Status = E_NOT_OK;
        LogString(u"Can not allocate video adapter\r\n");
        goto Cleanup;
    }

    (*VideoAdapter)->Info.Version = Gop->Mode->Info->Version;
    (*VideoAdapter)->Info.HorizontalResolution = Gop->Mode->Info->HorizontalResolution;
    (*VideoAdapter)->Info.VerticalResolution = Gop->Mode->Info->VerticalResolution;
    (*VideoAdapter)->Info.PixelFormat = (UINT8)Gop->Mode->Info->PixelFormat;
    (*VideoAdapter)->Info.PixelInformation.RedMask = Gop->Mode->Info->PixelInformation.RedMask;
    (*VideoAdapter)->Info.PixelInformation.GreenMask = Gop->Mode->Info->PixelInformation.GreenMask;
    (*VideoAdapter)->Info.PixelInformation.BlueMask = Gop->Mode->Info->PixelInformation.BlueMask;
    (*VideoAdapter)->Info.PixelInformation.ReservedMask = Gop->Mode->Info->PixelInformation.ReservedMask;
    (*VideoAdapter)->Info.PixelsPerScanLine = Gop->Mode->Info->PixelsPerScanLine;
    (*VideoAdapter)->FrameBufferBase = Gop->Mode->FrameBufferBase;
    (*VideoAdapter)->FrameBufferSize = Gop->Mode->FrameBufferSize;

Cleanup:
    return Status;
}
