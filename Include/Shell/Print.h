/**
 * @file Include/Shell/Print.h
 * @author LinhengXilan
 * @version 0.0.0.4
 * @date 2026-6-8
 */

#ifndef __SHELL_PRINT_H__
#define __SHELL_PRINT_H__

#include <Types.h>
#include <stdarg.h>

namespace Shell
{
	void PutChar(char ch);
	int32 Printf(const char* string, ...);
	int32 VSPrintf(char* buffer, const char* string, va_list args);
	int itoa(char* buffer, uint32 number, int base, int precision, bool sign);
	int itoa(char* buffer, uint64 number, int base, int precision, bool sign);
} // namespace Shell

#endif