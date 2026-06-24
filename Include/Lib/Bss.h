/**
 * @file Include/Lib/Bss.h
 * @author LinhengXilan
 * @version 0.0.0.5
 * @date 2026-6-25
 */

#ifndef __LIB_BSS_H__
#define __LIB_BSS_H__

#include <Types.h>

class Bss
{
public:
	void Initialize(uint64 kernelStart, uint64 kernelSize);
	uint64 Allocate(uint64 size);

private:
	uint64 _Address;
	uint64 _Size;
	uint64 _Capacity;
};

Bss* GetBss();

#endif