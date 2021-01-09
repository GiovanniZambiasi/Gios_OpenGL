#pragma once
#include "../Vector2.h"

namespace Gio::Rendering 
{
	class VertexBuffer
	{
	private:
		unsigned int _rendererID;

	public:
		VertexBuffer(const void* data, unsigned int size);

		~VertexBuffer();

		void Bind() const;

		void UnBind() const;
		
		void Translate(const Gio::Vector2& vector2)
		{
			
		}
	};
}
