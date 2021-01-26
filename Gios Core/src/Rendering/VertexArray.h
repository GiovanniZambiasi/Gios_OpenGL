#pragma once

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

namespace Gio::Rendering 
{
	class VertexArray
	{
	private:
		unsigned int _rendererID;

	public:
		VertexArray();

		~VertexArray();

		void AddBuffer(const VertexBuffer& vertices, const VertexBufferLayout& layout);

		void Bind() const;

		void UnBind() const;
	};
}
