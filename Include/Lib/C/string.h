/**
 * @file Include/Lib/string.h
 * @author LinhengXilan
 * @version 0.0.0.5
 * @date 2026-6-25
 */

#ifndef __LIB_C_STRING_H__
#define __LIB_C_STRING_H__

#include <Types.h>

int64 strlen(const char* str);
void memset(void* dst, char ch, uint64 size);

#endif