/**
 * @file Kernel/Kernel.cpp
 * @author LinhengXilan
 * @version 0.0.0.4
 * @date 2026-6-8
 */

#include <Bootloader/BootParam.h>
#include <Graphics/Graphics.h>
#include <Shell/Shell.h>
#include <Shell/Print.h>

extern "C"
{
	void Kernel(Bootloader::BootParam param);
}

void Kernel(Bootloader::BootParam param)
{
	Graphics::GetGraphics()->Initialize(param.Graphics);
	Shell::GetShell()->Initialize();

	// Bootloader::MemoryData memoryData = param.Memory;
	// Bootloader::MemoryDescriptor* memory = memoryData.MemoryMap;

	// Shell::Printf("Type\t\t\t\t\t\tPhysicalStart\t\tVirtualStart\t\tNumberOfPages\tAttribute\t");
	// Shell::Printf("Type\t\t\t\t\t\tPhysicalStart\t\tVirtualStart\t\tNumberOfPages\tAttribute\n");

	// for (uint64 i = 0; i < 100; ++i)
	//{
	//	// if (i % 2 == 1)
	//	//{
	//	Shell::Printf(
	//		"%s\t0x%16x\t0x%16x\t0x%8x\t\t%x\n",
	//		Bootloader::GetMemoryTypeName(memory[i].Type),
	//		memory[i].PhysicalStart,
	//		memory[i].VirtualStart,
	//		memory[i].NumberOfPages,
	//		memory[i].Attribute
	//	);
	//	//}
	//	// else
	//	// {
	//	// 	Shell::Printf(
	//	// 		"%s\t0x%16x\t0x%16x\t0x%8x\t\t%x",
	//	// 		Bootloader::GetMemoryTypeName(memory[i].Type),
	//	// 		memory[i].PhysicalStart,
	//	// 		memory[i].VirtualStart,
	//	// 		memory[i].NumberOfPages,
	//	// 		memory[i].Attribute
	//	// 	);
	//	// }
	// }
	while (1)
	{
	}
}