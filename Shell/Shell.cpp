/**
 * @file Shell/Shell.cpp
 * @author LinhengXilan
 * @version 0.0.0.5
 * @date 2026-6-25
 */

#include <Graphics/Graphics.h>
#include <Shell/Font.h>
#include <Shell/Shell.h>

static Shell ShellInstance;

Shell* GetShell()
{
	return &ShellInstance;
}

void Shell::Initialize()
{
	_CursorX = 0;
	_CursorY = 0;
	_CursorXMax = Graphics::GetGraphics()->GetHorizontalResolution() / 8;
}

void Shell::Write(char* string, uint16 length)
{
	for (int i = 0; i < length; ++i)
	{
		const uint8* ascii = ASCIIFont[static_cast<uint8>(string[i])];
		switch (string[i])
		{
		case '\n':
			_CursorX = 0;
			++_CursorY;
			break;
		case '\t':
			_CursorX = (_CursorX + 4) & 0b11111100;
			break;
		case 32 ... 126:
		{
			uint16 y = _CursorY * 16;
			for (int j = 0; j < 16; ++j)
			{
				uint16 x = _CursorX * 8;
				for (int k = 0; k < 8; ++k)
				{
					if (ascii[j] & (0b10000000 >> k))
					{
						Graphics::GetGraphics()->WritePixel(x + k, y + j, 0xFFFFFFFF);
					}
				}
			}
			++_CursorX;
			break;
		}
		default:
			break;
		}
		if (_CursorX == _CursorXMax)
		{
			++_CursorY;
			_CursorX = 0;
		}
	}
}