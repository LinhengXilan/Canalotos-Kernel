/**
 * @file Shell/Printf.cpp
 * @author LinhengXilan
 * @version 0.0.0.4
 * @date 2026-6-8
 */

#include <Shell/Print.h>
#include <stdarg.h>
#include <Bit.h>
#include <Lib/string.h>
#include <Shell/Shell.h>
#include <Lib/Math.h>

namespace Shell
{
	enum PrintfFlag : uint8
	{
		None = 0,
		Long = BIT(0),
		Sign = BIT(1),
		Char = BIT(2),
		Skip = BIT(3),
	};

	int32 Printf(const char* format, ...)
	{
		char buffer[1024];
		va_list args;
		va_start(args, format);
		int32 n = VSPrintf(buffer, format, args);
		va_end(args);
		GetShell()->Write(buffer, n);
		return n;
	}

	int32 VSPrintf(char* buffer, const char* format, va_list args)
	{
		char* string = buffer;
		while (*format != '\0')
		{
			uint8 precision = 0;
			uint8 base = 10;
			uint8 flags = PrintfFlag::None;
			if (*format != '%')
			{
				*string++ = *format++;
				continue;
			}

			++format; // 此时*format为%的下一个字符

			while (*(format) >= '1' && *(format) <= '9')
			{
				precision *= 10;
				precision += *(format++) - '0';
			}

			if (*(format) == 'l' || *(format) == 'L')
			{
				flags |= PrintfFlag::Long;
				++format;
			}

			switch (*format)
			{
			case 'b':
				base = 2;
				break;
			case 'c':
				*string++ = static_cast<char>(va_arg(args, uint32));
				flags |= PrintfFlag::Char;
				break;
			case 'd':
				flags |= PrintfFlag::Sign;
				break;
			case 'o':
				base = 8;
				break;
			case 's':
			{
				char* str = reinterpret_cast<char*>(va_arg(args, uint64));
				while (*str)
				{
					*string++ = *str++;
				}
				flags |= PrintfFlag::Char;
				break;
			}
			case 'u':
				break;
			case 'x':
				base = 16;
				break;
			case '%':
				*string++ = '%';
				break;
			default:
				flags |= PrintfFlag::Skip;
				*string++ = '%';
				break;
			}

			if (!(flags & PrintfFlag::Skip))
			{
				++format;
			}

			if (flags & PrintfFlag::Char)
			{
				continue;
			}

			if (flags & PrintfFlag::Long)
			{
				string += itoa(string, va_arg(args, uint64), base, precision, flags & PrintfFlag::Sign);
			}
			else
			{
				string += itoa(string, va_arg(args, uint32), base, precision, flags & PrintfFlag::Sign);
			}
			continue;
		}
		return string - buffer;
	}

	int itoa(char* buffer, uint32 number, int base, int precision, bool sign)
	{
		char tempBuffer[32];
		char* ptr = buffer;
		uint32 tempNumber = number;
		int n = 0;
		bool flag = false;

		if (sign && static_cast<int32>(number) < 0)
		{
			tempNumber = -static_cast<int32>(number);
			flag = true;
		}

		if (tempNumber == 0)
		{
			tempBuffer[n++] = '0';
		}
		while (tempNumber > 0)
		{
			char mod = static_cast<char>(tempNumber % base);
			tempBuffer[n++] = mod < 10 ? '0' + mod : 'A' + mod - 10;
			tempNumber /= base;
		}

		if (precision > n)
		{
			for (int i = 0; i < precision - n; i++)
			{
				*ptr++ = ' ';
			}
		}
		if (flag)
		{
			*ptr++ = '-';
		}

		for (int i = 1; i <= n; ++i)
		{
			*ptr++ = tempBuffer[n - i];
		}
		return ptr - buffer;
	}

	int itoa(char* buffer, uint64 number, int base, int precision, bool sign)
	{
		char tempBuffer[64];
		char* ptr = buffer;
		uint64 tempNumber = number;
		int n = 0;
		bool flag = false;

		if (sign && static_cast<int64>(number) < 0)
		{
			tempNumber = -static_cast<int64>(number);
			flag = true;
		}

		if (tempNumber == 0)
		{
			tempBuffer[n++] = '0';
		}
		while (tempNumber > 0)
		{
			char mod = static_cast<char>(tempNumber % base);
			tempBuffer[n++] = mod < 10 ? '0' + mod : 'A' + mod - 10;
			tempNumber /= base;
		}

		if (precision > n)
		{
			for (int i = 0; i < precision - n; i++)
			{
				*ptr++ = ' ';
			}
		}
		if (flag)
		{
			*ptr++ = '-';
		}

		for (int i = 1; i <= n; ++i)
		{
			*ptr++ = tempBuffer[n - i];
		}
		return ptr - buffer;
	}

} // namespace Shell