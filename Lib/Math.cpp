/**
 * @file Lib/Math.cpp
 * @author LinhengXilan
 * @version 0.0.0.4
 * @date 2026-6-8
 */

#include <Lib/Math.h>

int Digits(uint64 number, int base)
{
	int n = 0;
	while (number)
	{
		number /= base;
		++n;
	}
	return n;
}