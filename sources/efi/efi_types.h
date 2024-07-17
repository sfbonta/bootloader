#ifndef _EFI_TYPES_H_
#define _EFI_TYPES_H_

#define EFI_API __attribute__((ms_abi))
#define EFI_PACKED __attribute__((packed))

#include "system_memory_types.h"

#define IN
#define OUT
#define OPTIONAL
#define CONST const

typedef char INT8;
typedef short INT16;
typedef int INT32;
typedef long long int INT64;

typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned int UINT32;
typedef unsigned long long int UINT64;

typedef INT64 INTN;
typedef UINT64 UINTN;

typedef UINT8 CHAR8;
typedef UINT16 CHAR16;

typedef UINT8 BOOLEAN;
#define TRUE 1
#define FALSE 0

typedef void VOID;
#define NULL_PTR (VOID *)0

typedef struct _EFI_GUID
{
    UINT32 Data1;
    UINT16 Data2;
    UINT16 Data3;
    UINT8 Data4[8];
} EFI_PACKED EFI_GUID;

typedef UINTN EFI_STATUS;

typedef VOID *EFI_HANDLE;
typedef VOID *EFI_EVENT;

typedef UINT64 EFI_LBA;
typedef UINTN EFI_TPL;

typedef struct _EFI_MAC_ADDRESS
{
    UINT8 MacAddress[32];
} EFI_PACKED EFI_MAC_ADDRESS;

typedef struct _EFI_IPv4_ADDRESS
{
    UINT8 Ipv4Address[4];
} EFI_PACKED EFI_IPv4_ADDRESS;

typedef struct _EFI_IPv6_ADDRESS
{
    UINT8 Ipv6Address[16];
} EFI_PACKED EFI_IPv6_ADDRESS;

typedef struct _EFI_IP_ADRESS
{
    UINT8 IpAddress[16];
} EFI_PACKED EFI_IP_ADRESS;

typedef UINT64 EFI_PHYSICAL_ADDRESS;
typedef UINT64 EFI_VIRTUAL_ADDRESS;

typedef enum _EFI_ALLOCATE_TYPE
{
    AllocateAnyPages,
    AllocateMaxAddress,
    AllocateAddress,
    MaxAllocateType
} EFI_ALLOCATE_TYPE;

typedef enum _EFI_MEMORY_TYPE
{
    EfiReservedMemoryType,
    EfiLoaderCode,
    EfiLoaderData,
    EfiBootServicesCode,
    EfiBootServicesData,
    EfiRuntimeServicesCode,
    EfiRuntimeServicesData,
    EfiConventionalMemory,
    EfiUnusableMemory,
    EfiACPIReclaimMemory,
    EfiACPIMemoryNVS,
    EfiMemoryMappedIO,
    EfiMemoryMappedIOPortSpace,
    EfiPalCode,
    EfiPersistentMemory,
    EfiUnacceptedMemoryType,
    EfiMaxMemoryType
} EFI_MEMORY_TYPE;


typedef struct _EFI_DEVICE_PATH_PROTOCOL
{
    UINT8 Type;
    UINT8 SubType;
    UINT8 Length[2];
} EFI_DEVICE_PATH_PROTOCOL;

typedef VOID(EFI_API *EFI_EVENT_NOTIFY)(
    IN EFI_EVENT Event,
    IN VOID *Context);

typedef enum _EFI_INTERFACE_TYPE
{
    EFI_NATIVE_INTERFACE
} EFI_INTERFACE_TYPE;

typedef enum _EFI_LOCATE_SEARCH_TYPE
{
    AllHandles,
    ByRegisterNotify,
    ByProtocol
} EFI_LOCATE_SEARCH_TYPE;

typedef struct _EFI_OPEN_PROTOCOL_INFORMATION_ENTRY
{
    EFI_HANDLE AgentHandle;
    EFI_HANDLE ControllerHandle;
    UINT32 Attributes;
    UINT32 OpenCount;
} EFI_OPEN_PROTOCOL_INFORMATION_ENTRY;

typedef enum _EFI_TIMER_DELAY
{
    TimerCancel,
    TimerPeriodic,
    TimerRelative,
} EFI_TIMER_DELAY;

typedef struct _EFI_TIME
{
    UINT16 Year;
    UINT8 Month;
    UINT8 Day;
    UINT8 Hour;
    UINT8 Minute;
    UINT8 Second;
    UINT8 Pad1;
    UINT32 Nanosecond;
    INT16 TimeZone;
    UINT8 Daylight;
    UINT8 Pad2;
} EFI_TIME;

typedef struct _EFI_TIME_CAPABILITIES
{
    UINT32 Resolution;
    UINT32 Accuracy;
    BOOLEAN SetsToZero;
} EFI_TIME_CAPABILITIES;

typedef enum _EFI_RESET_TYPE
{
    EfiResetCold,
    EfiResetWarm,
    EfiResetShutdown,
    EfiResetPlatformSpecific
} EFI_RESET_TYPE;

typedef struct _EFI_CAPSULE_BLOCK_DESCRIPTOR
{
    UINT64 Length;
    union
    {
        EFI_PHYSICAL_ADDRESS DataBlock;
        EFI_PHYSICAL_ADDRESS ContinuationPointer;
    } Union;
} EFI_CAPSULE_BLOCK_DESCRIPTOR;

typedef struct _EFI_CAPSULE_HEADER
{
    EFI_GUID CapsuleGuid;
    UINT32 HeaderSize;
    UINT32 Flags;
    UINT32 CapsuleImageSize;
} EFI_CAPSULE_HEADER;

typedef struct _EFI_CAPSULE_TABLE
{
    UINT32 CapsuleArrayNumber;
    VOID *CapsulePtr[1];
} EFI_CAPSULE_TABLE;

typedef struct _EFI_MEMORY_RANGE
{
    EFI_PHYSICAL_ADDRESS Address;
    UINT64 Length;
} EFI_MEMORY_RANGE;

typedef struct _EFI_MEMORY_RANGE_CAPSULE
{
    EFI_CAPSULE_HEADER Header;
    UINT32 OsRequestedMemoryType;
    UINT64 NumberOfMemoryRanges;
    EFI_MEMORY_RANGE MemoryRanges[];
} EFI_MEMORY_RANGE_CAPSULE;

typedef struct _EFI_MEMORY_RANGE_CAPSULE_RESULT
{
    UINT64 FirmwareMemoryRequirement;
    UINT64 NumberOfMemoryRanges;
} EFI_MEMORY_RANGE_CAPSULE_RESULT;

typedef struct _EFI_FILE_IO_TOKEN
{
    EFI_EVENT Event;
    EFI_STATUS Status;
    UINTN BufferSize;
    VOID *Buffer;
} EFI_FILE_IO_TOKEN;

typedef struct _EFI_FILE_INFO
{
    UINT64 Size;
    UINT64 FileSize;
    UINT64 PhysicalSize;
    EFI_TIME CreateTime;
    EFI_TIME LastAccessTime;
    EFI_TIME ModificationTime;
    UINT64 Attribute;
    CHAR16 FileName[1024];
} EFI_FILE_INFO;

#endif /* _EFI_TYPES_H_ */
