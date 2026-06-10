/**
 * @file Include/Shell/Shell.h
 * @author LinhengXilan
 * @version 0.0.0.4
 * @date 2026-6-8
 */

#ifndef __SHELL_SHELL_H__
#define __SHELL_SHELL_H__

#include <Types.h>
#include <Bootloader/BootParam.h>

namespace Shell
{
	class Shell
	{
	public:
		Shell() = default;
		void Initialize();

	public:
		void Write(char* string, uint16 length);

	private:
		uint16 _CursorX = 0;
		uint16 _CursorY = 0;
		uint16 _CursorXMax = 0;
	};

	Shell* GetShell();
} // namespace Shell

#endif