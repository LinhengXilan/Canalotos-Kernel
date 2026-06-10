/**
 * @file Include/Bootloader/BootParam.h
 * @author LinhengXilan
 * @version 0.0.0.4
 * @date 2026-6-8
 */

#ifndef __BOOTLOADER_BOOTPARAM_H__
#define __BOOTLOADER_BOOTPARAM_H__

#include <Types.h>

namespace Bootloader
{
	struct GraphicsData
	{
		uint64 FrameBufferBase;
		uint64 FrameBufferSize;
		uint32 HorizontalResolution;
		uint32 VerticalResolution;
	};

	enum class EfiMemoryType : uint32
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
	};

	const char* GetMemoryTypeName(EfiMemoryType type);

	struct MemoryDescriptor
	{
		EfiMemoryType Type;
		uint32 Reserved0;
		uint64 PhysicalStart;
		uint64 VirtualStart;
		uint64 NumberOfPages;
		uint64 Attribute;
		uint64 Reserved1;
	};

	struct MemoryData
	{
		uint64 MemoryMapSize;
		MemoryDescriptor* MemoryMap;
		uint64 MapKey;
		uint64 DescriptorSize;
		uint32 DescriptorVersion;
	};

	struct BootParam
	{
		GraphicsData Graphics;
		MemoryData Memory;
	};
} // namespace Bootloader

#endif