/**
 * @file Bootloader/BootParam.cpp
 * @author LinhengXilan
 * @version 0.0.0.4
 * @date 2026-6-8
 */

#include <Bootloader/BootParam.h>

namespace Bootloader
{
	const char* GetMemoryTypeName(EfiMemoryType type)
	{
		switch (type)
		{
		case EfiMemoryType::EfiReservedMemoryType:
			return "EfiReservedMemoryType     ";
		case EfiMemoryType::EfiLoaderCode:
			return "EfiLoaderCode             ";
		case EfiMemoryType::EfiLoaderData:
			return "EfiLoaderData             ";
		case EfiMemoryType::EfiBootServicesCode:
			return "EfiBootServicesCode       ";
		case EfiMemoryType::EfiBootServicesData:
			return "EfiBootServicesData       ";
		case EfiMemoryType::EfiRuntimeServicesCode:
			return "EfiRuntimeServicesCode    ";
		case EfiMemoryType::EfiRuntimeServicesData:
			return "EfiRuntimeServicesData    ";
		case EfiMemoryType::EfiConventionalMemory:
			return "EfiConventionalMemory     ";
		case EfiMemoryType::EfiUnusableMemory:
			return "EfiUnusableMemory         ";
		case EfiMemoryType::EfiACPIReclaimMemory:
			return "EfiACPIReclaimMemory      ";
		case EfiMemoryType::EfiACPIMemoryNVS:
			return "EfiACPIMemoryNVS          ";
		case EfiMemoryType::EfiMemoryMappedIO:
			return "EfiMemoryMappedIO         ";
		case EfiMemoryType::EfiMemoryMappedIOPortSpace:
			return "EfiMemoryMappedIOPortSpace";
		case EfiMemoryType::EfiPalCode:
			return "EfiPalCode                ";
		case EfiMemoryType::EfiPersistentMemory:
			return "EfiPersistentMemory       ";
		case EfiMemoryType::EfiUnacceptedMemoryType:
			return "EfiUnacceptedMemoryType   ";
		case EfiMemoryType::EfiMaxMemoryType:
			return "EfiMaxMemoryType          ";
		default:
			return "Unknown                   ";
		}
	}
} // namespace Bootloader