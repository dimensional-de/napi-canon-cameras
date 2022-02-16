Please unpack the EDSDK as `EDSDK/` into this folder.

EDSDK 13.14.40 has an error in `EDSDKTypes.h` that triggers a conflict.
Change the "ObjectFormat Code (line 865-873)" to:

```cpp
typedef enum
{
    kEdsObjectFormat_Unknown   = 0x00000000,
    kEdsObjectFormat_Jpeg      = 0x3801,
    kEdsObjectFormat_CR2       = 0xB103,
    kEdsObjectFormat_MP4       = 0xB982,
    kEdsObjectFormat_CR3       = 0xB108,
    kEdsObjectFormat_HEIF_CODE = 0xB10B,
} EdsObjectFormat;
```
