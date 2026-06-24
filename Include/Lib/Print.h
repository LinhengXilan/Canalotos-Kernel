/**
 * @file Include/Shell/Print.h
 * @author LinhengXilan
 * @version 0.0.0.5
 * @date 2026-6-25
 */

#ifndef __SHELL_PRINT_H__
#define __SHELL_PRINT_H__

#include <Types.h>
#include <Lib/C/stdarg.h>

void PutChar(char ch);
int32 Printf(const char* string, ...);
int32 VSPrintf(char* buffer, const char* string, va_list args);
int itoa(char* buffer, uint32 number, int base, int precision, bool sign);
int itoa(char* buffer, uint64 number, int base, int precision, bool sign);

void InitPrintf();

#endif