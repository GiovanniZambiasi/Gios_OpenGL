#pragma once
#include "Rendering/VertexArray.h"
#include "Rendering/IndexBuffer.h"
#include "Rendering/Shader.h"

namespace Gio 
{
	class Object2D
	{
	private:
		Rendering::VertexArray _vertexArray;
		Rendering::VertexBuffer _vertexBuffer;
		Rendering::IndexBuffer _indexBuffer;
		Rendering::Shader _shader;

	public:
		Object2D(float vertices[], unsigned int indices[]);

		~Object2D();

		void Render();
	};
}
