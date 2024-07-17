#ifndef _EFI_EVENT_GROUP_DEFINES_H_
#define _EFI_EVENT_GROUP_DEFINES_H_

#define EFI_EVENT_GROUP_EXIT_BOOT_SERVICES                                             \
    {                                                                                  \
        0x27abf055, 0xb1b8, 0x4c26, { 0x80, 0x48, 0x74, 0x8f, 0x37, 0xba, 0xa2, 0xdf } \
    }

#define EFI_EVENT_GROUP_BEFORE_EXIT_BOOT_SERVICES                                      \
    {                                                                                  \
        0x8be0e274, 0x3970, 0x4b44, { 0x80, 0xc5, 0x1a, 0xb9, 0x50, 0x2f, 0x3b, 0xfc } \
    }

#define EFI_EVENT_GROUP_VIRTUAL_ADDRESS_CHANGE                    \
    {                                                             \
        0x13fa7698, 0xc831, 0x49c7, 0x87, 0xea, 0x8f, 0x43, 0xfc, \
            0xc2, 0x51, 0x96                                      \
    }

#define EFI_EVENT_GROUP_MEMORY_MAP_CHANGE                        \
    {                                                            \
        0x78bee926, 0x692f, 0x48fd, 0x9e, 0xdb, 0x1, 0x42, 0x2e, \
            0xf0, 0xd7, 0xab                                     \
    }

#define EFI_EVENT_GROUP_READY_TO_BOOT                             \
    {                                                             \
        0x7ce88fb3, 0x4bd7, 0x4679, 0x87, 0xa8, 0xa8, 0xd8, 0xde, \
            0xe5, 0xd, 0x2b                                       \
    }

#define EFI_EVENT_GROUP_AFTER_READY_TO_BOOT                                           \
    {                                                                                 \
        0x3a2a00ad, 0x98b9, 0x4cdf, { 0xa4, 0x78, 0x70, 0x27, 0x77, 0xf1, 0xc1, 0xb } \
    }

#define EFI_EVENT_GROUP_RESET_SYSTEM                       \
    {                                                      \
        0x62da6a56, 0x13fb, 0x485a,                        \
        {                                                  \
            0xa8, 0xda, 0xa3, 0xdd, 0x79, 0x12, 0xcb, 0x6b \
        }                                                  \
    }

#endif /* _EFI_EVENT_GROUP_DEFINES_H_ */
