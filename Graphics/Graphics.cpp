/**
 * @file Graphics/Graphics.cpp
 * @author LinhengXilan
 * @version 0.0.0.4
 * @date 2026-6-8
 */

#include <Graphics/Graphics.h>

namespace Graphics
{
	static Graphics GraphicsInstance;

	Graphics* GetGraphics()
	{
		return &GraphicsInstance;
	}

	void Graphics::Initialize(Bootloader::GraphicsData graphics)
	{
		_BufferBase = graphics.FrameBufferBase;
		_BufferSize = graphics.FrameBufferSize;
		_HorizontalResolution = graphics.HorizontalResolution;
		_VerticalResolution = graphics.VerticalResolution;
	}

	void Graphics::WritePixel(uint32 x, uint32 y, uint32 color)
	{
		*reinterpret_cast<uint32*>(_BufferBase + (_HorizontalResolution * y + x) * 4) = color;
	}

	uint64 Graphics::GetBufferBase()
	{
		return _BufferBase;
	}

	int64 Graphics::GetBufferSize()
	{
		return _BufferSize;
	}

	uint32 Graphics::GetHorizontalResolution()
	{
		return _HorizontalResolution;
	}

	uint32 Graphics::GetVerticalResolution()
	{
		return _VerticalResolution;
	}
} // namespace Graphics