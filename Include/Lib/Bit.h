/**
 * @file Include/Lib/Bit.h
 * @author LinhengXilan
 * @version 0.0.0.5
 * @date 2026-6-25
 */

#ifndef __BIT_H__
#define __BIT_H__

#include <Types.h>

constexpr uint64 BIT(uint8 bit)
{
	if (bit > 63)
	{
		return 0;
	}
	return 1 << bit;
}

#endif