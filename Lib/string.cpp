/**
 * @file Lib/string.cpp
 * @author LinhengXilan
 * @version 0.0.0.5
 * @date 2026-6-25
 */

#include <Lib/C/string.h>

int64 strlen(const char* str)
{
	const char* sc;
	for (sc = str; *sc != '\0'; ++sc)
	{
	}
	return sc - str;
}

void memset(void* dst, char ch, uint64 size)
{
	for(uint64 i = 0; i < size; ++i)
	{
		reinterpret_cast<char*>(dst)[i] = ch;
	}
}