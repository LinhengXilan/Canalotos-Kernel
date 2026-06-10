/**
 * @file Include/Graphics/Graphics.h
 * @author LinhengXilan
 * @version 0.0.0.4
 * @date 2026-6-8
 */

#ifndef __GRAPHICS_GRAPHICS_H__
#define __GRAPHICS_GRAPHICS_H__

#include <Types.h>
#include <Bootloader/BootParam.h>

namespace Graphics
{
	class Graphics
	{
	public:
		Graphics() = default;

		void Initialize(Bootloader::GraphicsData graphics);
		void WritePixel(uint32 x, uint32 y, uint32 color);

	public:
		uint64 GetBufferBase();
		int64 GetBufferSize();
		uint32 GetHorizontalResolution();
		uint32 GetVerticalResolution();
	private:
		uint64 _BufferBase = 0;
		int64 _BufferSize = 0;
		uint32 _HorizontalResolution = 0;
		uint32 _VerticalResolution = 0;
	};

	Graphics* GetGraphics();
} // namespace Graphics

#endif