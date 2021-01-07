#pragma once

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
	};
}