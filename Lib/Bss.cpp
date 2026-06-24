/**
 * @file Lib/Bss.cpp
 * @author LinhengXilan
 * @version 0.0.0.5
 * @date 2026-6-25
 */

#include <Lib/Bss.h>
#include <Linkage.h>

static Bss bssInstance;

Bss* GetBss()
{
	return &bssInstance;
}

void Bss::Initialize(uint64 kernelStart, uint64 kernelSize)
{
	_Address = reinterpret_cast<uint64>((kernelStart + kernelSize) + 0xFFFF) & ~0xFFFF;
	_Capacity = 0x100000 - kernelSize;
	_Size = 0;
}

uint64 Bss::Allocate(uint64 size)
{
	if(_Size + size > _Capacity)
	{
		return NULL;
	}
	_Size += size;
	return _Address + _Size - size;
}