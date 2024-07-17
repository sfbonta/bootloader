#include "hii_loader.h"

#include "protocols/efi_hii_font_protocol.h"
#include "utils.h"

STATUS HiiLetterLoader(CONST IN EFI_BOOT_SERVICES *BootServices, OUT HII_CHARACTERS **Charaters)
{
    STATUS Status = E_OK;
    EFI_IMAGE_OUTPUT *ImageOutput = NULL_PTR;
    EFI_GUID HiiFontProtocolGuid = EFI_HII_FONT_PROTOCOL_GUID;
    EFI_HII_FONT_PROTOCOL *Hiifp = NULL_PTR;

    if (NULL_PTR == Charaters)
    {
        Status = E_NOT_OK;
        goto Cleanup;
    }

    BootServices->LocateProtocol(&HiiFontProtocolGuid, NULL_PTR, (VOID **)&Hiifp);
    if (NULL_PTR == Hiifp)
    {
        Status = E_NOT_OK;
        goto Cleanup;
    }

    BootServices->AllocatePool(EfiLoaderData, sizeof(**Charaters), (VOID **)Charaters);
    if (NULL_PTR == *Charaters)
    {
        Status = E_NOT_OK;
        goto Cleanup;
    }

    for (UINT16 letter = 0; letter < 0x100; ++letter)
    {
        Hiifp->GetGlyph(Hiifp, letter, NULL_PTR, &ImageOutput, NULL_PTR);

        (*Charaters)->Letters[letter].LetterWidth = ImageOutput->Width;
        (*Charaters)->Letters[letter].LetterHeight = ImageOutput->Height;
        BootServices->AllocatePool(EfiLoaderData, ImageOutput->Width * ImageOutput->Height, (VOID **)&((*Charaters)->Letters[letter].LetterBuffer));

        for (UINT64 i = 0 ; i < ImageOutput->Width * ImageOutput->Height ; ++i)
        {
            (*Charaters)->Letters[letter].LetterBuffer[i] = ImageOutput->Image.Bitmap[i].Blue;
        }

        BootServices->FreePool(ImageOutput);
        ImageOutput = NULL_PTR;
    }

Cleanup:
    if (E_OK != Status)
    {
        if (NULL_PTR != Charaters)
        {
            if (NULL_PTR != *Charaters)
            {
                BootServices->FreePool(*Charaters);
                *Charaters = NULL_PTR;
            }
        }
    }

    return Status;
}
