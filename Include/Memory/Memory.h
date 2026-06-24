/**
 * @file Include/Memory/Memory.h
 * @author LinhengXilan
 * @version 0.0.0.5
 * @date 2026-6-25
 */

#ifndef __MEMORY_MEMORY_H__
#define __MEMORY_MEMORY_H__

#include <Types.h>
#include <Bootloader/BootParam.h>

enum class MemoryType : uint8
{
	Unusable,
	Avaliable,
	Firmware,
	System,
	User
};

enum MemoryAttribute : uint8
{
	Normal
};

struct MemoryDecriptor
{
	MemoryType type;
	MemoryAttribute Attribute;
	uint16 Reserved0;
	uint32 Reserved1;
	uint64 Address;
	uint64 Size;
};

class Memory
{
public:
	void Initialize(EfiMemoryDescriptor* memoryMap, uint64 memoryMapSize);

public:
	MemoryDecriptor* GetDescriptor();
	uint8 GetDescriptorSize();

	static const char* GetMemoryTypeString(MemoryType type);

private:
	MemoryDecriptor* _Descriptor;
	uint8 _DescriptorSize = 0;
};

extern MemoryDecriptor* __Descriptor;

Memory* GetMemory();

#endif