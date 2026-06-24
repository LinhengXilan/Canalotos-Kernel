/**
 * @file Include/Bootloader/BootParam.h
 * @author LinhengXilan
 * @version 0.0.0.5
 * @date 2026-6-25
 */

#ifndef __BOOTLOADER_BOOTPARAM_H__
#define __BOOTLOADER_BOOTPARAM_H__

#include <Types.h>
#include <Lib/Bit.h>

struct EfiGraphicsData
{
	uint64 FrameBufferBase;
	uint64 FrameBufferSize;
	uint32 HorizontalResolution;
	uint32 VerticalResolution;
};

enum class EfiMemoryType : uint32
{
	EfiReservedMemoryType,		/// 不可用。
	EfiLoaderCode,				/// UEFI操作系统加载器或操作系统可能在合适的情况下使用此内存。
	EfiLoaderData,				/// UEFI操作系统加载器或操作系统可能在合适的情况下使用此内存。
	EfiBootServicesCode,		/// 可使用的通用内存。
	EfiBootServicesData,		/// 可使用的通用内存。
	EfiRuntimeServicesCode,		/// 此内存为UEFI操作系统加载器、工作中的操作系统和ACPI S1-S3保留。
	EfiRuntimeServicesData,		/// 此内存为UEFI操作系统加载器、工作中的操作系统和ACPI S1-S3保留。
	EfiConventionalMemory,		/// 可使用的通用内存。
	EfiUnusableMemory,			/// 含有错误的内存，不可使用。
	EfiACPIReclaimMemory,		/// 此内存为UEFI操作系统加载器和操作系统保留，直到启用ACPI。ACPI启用后，此内存为可使用的通用内存。
	EfiACPIMemoryNVS,			/// 此内存为UEFI操作系统加载器、工作中的操作系统和ACPI S1-S3保留。
	EfiMemoryMappedIO,			/// 此内存不可被操作系统使用。
	EfiMemoryMappedIOPortSpace,	/// 此内存不可被操作系统使用。
	EfiPalCode,					/// 此内存为UEFI操作系统加载器、工作中的操作系统和ACPI S1-S4保留。此内存还可能具有由处理器实现定义的其他属性。
	EfiPersistentMemory,		/// 此内存作为EfiConventionalMemory，且支持非易失性字节寻址。
	EfiUnacceptedMemoryType,	/// 未接收的内存，需要被启动目标接收后才可使用。
	EfiMaxMemoryType			
};

enum EfiMemoryAttribute
{
	EFI_MEMORY_UC              = BIT(1),	/// 内存可缓存属性：内存区域支持设置为不可缓存。
	EFI_MEMORY_WC              = 0x0000000000000002,	/// 内存可缓存属性：内存区域支持配置为写入合并
	EFI_MEMORY_WT              = 0x0000000000000004,	/// 内存可缓存属性：该内存区域支持配置为具有“write through”策略的可缓存区域。在缓存中命中的写入操作也会被写入主内存。
	EFI_MEMORY_WB              = 0x0000000000000008,	/// 内存可缓存属性：该内存区域支持配置为具有“writeback”策略的可缓存区域。在缓存中命中的读写操作不会传播到主内存。当分配新的缓存行时，脏数据会被回写到主内存。
	EFI_MEMORY_UCE             = 0x0000000000000010,	/// 内存可缓存属性：该内存区域支持配置为不可缓存、可导出，并支持“fetch与add”信号量机制。
	EFI_MEMORY_WP              = 0x0000000000001000,	/// 物理内存保护属性：该内存区域支持通过系统硬件配置为写保护。目前，这通常用作缓存能力属性。该内存区域支持配置为具有“写保护”策略的可缓存。读取操作尽可能从缓存行获取，读取未命中时会导致缓存填充。写入操作会传播到系统总线，并导致总线上所有处理器上的相应缓存行失效。
	EFI_MEMORY_RP              = 0x0000000000002000,	/// 物理内存保护属性：该内存区域支持由系统硬件配置为只读保护。
	EFI_MEMORY_XP              = 0x0000000000004000,	/// 物理内存保护属性：该内存区域支持配置，以便通过系统硬件保护其免受代码执行。
	EFI_MEMORY_NV              = 0x0000000000008000,	/// 运行时内存属性：该内存区域指的是持久内存。
	EFI_MEMORY_MORE_RELIABLE   = 0x0000000000010000,	/// 相对于系统中的其他内存，该内存区域具有更高的可靠性。如果所有内存的可靠性相同，则不使用此位。
	EFI_MEMORY_RO              = 0x0000000000020000,	/// 物理内存保护属性：该内存区域支持系统硬件将此内存范围设置为只读。
	EFI_MEMORY_SP              = 0x0000000000040000,	/// 专用内存（SPM）。该内存专为特定目的而预留，如用于特定的设备驱动程序或应用程序。SPM属性作为操作系统（OS）的一个提示，以避免将此内存分配给无法重定位的核心操作系统数据或代码。若将此内存长期用于预期目的之外的其他用途，可能会导致平台性能不佳。
	EFI_MEMORY_CPU_CRYPTO      = 0x0000000000080000,	/// 如果此标志已设置，则该内存区域能够通过CPU的内存加密功能进行保护。如果此标志未设置，则该内存区域无法通过CPU的内存加密功能进行保护，或者CPU不支持CPU内存加密功能。
	EFI_MEMORY_HOT_PLUGGABLE   = 0x0000000000100000,	/// 如果此标志已设置，则表示该内存区域存在，并且能够动态地从平台上移除内存。此属性在操作系统（OS）的ACPI子系统初始化之前向操作系统提供提示，以避免将此内存分配给在运行时无法动态重定位的核心操作系统数据或代码。如果此标志未设置，则表示该内存区域在运行时无法从平台上动态移除。
	EFI_MEMORY_RUNTIME         = 0x8000000000000000,	/// 运行时内存属性：当调用SetVirtualAddressMap()函数时，操作系统需要为该内存区域分配虚拟映射（如虚拟内存服务中所述）。
	EFI_MEMORY_ISA_VALID       = 0x4000000000000000,	/// 如果设置了此标志，则该内存区域将使用EFI_MEMORY_ISA_MASK中指定的其他特定于指令集架构（ISA）的内存属性进行描述。
	EFI_MEMORY_ISA_MASK        = 0x0FFFF00000000000		/// 定义了用于描述可选的特定于指令集架构（ISA）的可缓存性属性的保留位，这些属性未包含在标准统一可扩展固件接口（UEFI）内存属性可缓存性位（EFI_MEMORY_UC、EFI_MEMORY_WC、EFI_MEMORY_WT、EFI_MEMORY_WB和EFI_MEMORY_UCE）中。有关这些位的更多特定于ISA的枚举信息，请参阅调用约定。
};

const char* GetMemoryTypeName(EfiMemoryType type);

struct EfiMemoryDescriptor
{
	EfiMemoryType Type;
	uint32 Reserved0;
	uint64 PhysicalStart;
	uint64 VirtualStart;
	uint64 NumberOfPages;
	uint64 Attribute;
	uint64 Reserved1;
};

struct EfiMemoryData
{
	uint64 MemoryMapSize;
	EfiMemoryDescriptor* MemoryMap;
	uint64 MapKey;
	uint64 DescriptorSize;
	uint32 DescriptorVersion;
};

struct BootParam
{
	EfiGraphicsData Graphics;
	EfiMemoryData Memory;
	uint64 KernelAddress;
	uint64 KernelSize;
};

#endif