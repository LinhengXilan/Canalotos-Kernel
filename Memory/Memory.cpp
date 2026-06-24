/**
 * @file Memory/Memory.cpp
 * @author LinhengXilan
 * @version 0.0.0.5
 * @date 2026-6-25
 */

#include <Memory/Memory.h>
#include <Lib/Print.h>
#include <Lib/Bss.h>

static Memory memoryInstance;
MemoryDecriptor* __Descriptor;

Memory* GetMemory()
{
	return &memoryInstance;
}

MemoryType GetMemoryType(EfiMemoryType type)
{
	switch (type)
	{
	case EfiMemoryType::EfiReservedMemoryType:
		return MemoryType::Unusable;

	case EfiMemoryType::EfiLoaderCode:
	case EfiMemoryType::EfiLoaderData:
		return MemoryType::Firmware;

	case EfiMemoryType::EfiBootServicesCode:
	case EfiMemoryType::EfiBootServicesData:
		return MemoryType::Avaliable;

	case EfiMemoryType::EfiRuntimeServicesCode:
	case EfiMemoryType::EfiRuntimeServicesData:
		return MemoryType::Firmware;

	case EfiMemoryType::EfiConventionalMemory:
		return MemoryType::Avaliable;

	case EfiMemoryType::EfiUnusableMemory:
		return MemoryType::Unusable;

	case EfiMemoryType::EfiACPIReclaimMemory:
	case EfiMemoryType::EfiACPIMemoryNVS:
	case EfiMemoryType::EfiMemoryMappedIO:
	case EfiMemoryType::EfiMemoryMappedIOPortSpace:
	case EfiMemoryType::EfiPalCode:
		return MemoryType::Firmware;

	case EfiMemoryType::EfiPersistentMemory:
		return MemoryType::Avaliable;

	case EfiMemoryType::EfiUnacceptedMemoryType:
	default:
		return MemoryType::Unusable;
	}
}

void Memory::Initialize(EfiMemoryDescriptor* memoryMap, uint64 memoryMapSize)
{
	__Descriptor = reinterpret_cast<MemoryDecriptor*>(GetBss()->Allocate(sizeof(MemoryDecriptor) * 16));
	_Descriptor = __Descriptor;
	_DescriptorSize = 0;
	_Descriptor[_DescriptorSize].Address = memoryMap[0].PhysicalStart;
	_Descriptor[_DescriptorSize].type = GetMemoryType(memoryMap[0].Type);
	_Descriptor[_DescriptorSize].Size = memoryMap[0].NumberOfPages;
	_Descriptor[_DescriptorSize].Attribute = MemoryAttribute::Normal;

	for (uint64 i = 1; i < memoryMapSize; ++i)
	{
		if (GetMemoryType(memoryMap[i].Type) == _Descriptor[_DescriptorSize].type)
		{
			_Descriptor[_DescriptorSize].Size += memoryMap[i].NumberOfPages;
		}
		else
		{
			++_DescriptorSize;
			_Descriptor[_DescriptorSize].Address = memoryMap[i].PhysicalStart;
			_Descriptor[_DescriptorSize].type = GetMemoryType(memoryMap[i].Type);
			_Descriptor[_DescriptorSize].Size = memoryMap[i].NumberOfPages;
			_Descriptor[_DescriptorSize].Attribute = MemoryAttribute::Normal;
		}
	}
}

MemoryDecriptor* Memory::GetDescriptor()
{
	return _Descriptor;
}

uint8 Memory::GetDescriptorSize()
{
	return _DescriptorSize;
}

const char* Memory::GetMemoryTypeString(MemoryType type)
{
	switch (type)
	{
	case MemoryType::Unusable:
		return "Unusable";
	case MemoryType::Avaliable:
		return "Avaliable";
	case MemoryType::Firmware:
		return "Firmware";
	case MemoryType::System:
		return "System";
	case MemoryType::User:
		return "User";
	default:
		return "Unknown";
	}
}