/**
 * @file Lib/string.cpp
 * @author LinhengXilan
 * @version 0.0.0.4
 * @date 2026-6-8
 */

#include <Lib/string.h>

maxint strlen(const char* str)
{
	const char* sc;
	for (sc = str; *sc != '\0'; ++sc)
	{
	}
	return sc - str;
}