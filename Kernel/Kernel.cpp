/**
 * @file Kernel/Kernel.cpp
 * @author LinhengXilan
 * @version 0.0.0.5
 * @date 2026-6-25
 */

#include <Bootloader/BootParam.h>
#include <Graphics/Graphics.h>
#include <Shell/Shell.h>
#include <Lib/Print.h>
#include <Memory/Memory.h>
#include <Lib/Bss.h>
#include <Linkage.h>

extern "C" int Kernel(BootParam param)
{
	GetBss()->Initialize(param.KernelAddress, param.KernelSize);
	Graphics::GetGraphics()->Initialize(param.Graphics);
	GetShell()->Initialize();
	InitPrintf();

	EfiMemoryData memoryData = param.Memory;
	GetMemory()->Initialize(memoryData.MemoryMap, memoryData.MemoryMapSize / sizeof(EfiMemoryDescriptor));
	Printf("0x%lx\n", reinterpret_cast<uint64>(GetMemory()->GetDescriptor()));
	Printf("Type\t\t\tStartAddress\t\tSize\n");

	for (uint8 i = 0; i < GetMemory()->GetDescriptorSize(); ++i)
	{
		Printf(
			"%s\t\t0x%16lx\t0x%16lx\n",
			Memory::GetMemoryTypeString(GetMemory()->GetDescriptor()[i].type),
			GetMemory()->GetDescriptor()[i].Address,
			GetMemory()->GetDescriptor()[i].Size
		);
	}

	while (1)
	{
	}
	return 0;
}