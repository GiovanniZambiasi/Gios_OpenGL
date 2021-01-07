#include "Object2D.h"
#include "Rendering/VertexBuffer.h"

namespace Gio 
{
	Object2D::Object2D(float vertices[], unsigned int indices[])
		:	_indexBuffer(indices, 6)
		,	_shader(Rendering::Shader("res/Shaders/Basic.shader"))
	{
		Rendering::VertexBuffer* vertexBuffer = new Rendering::VertexBuffer(vertices, 4 * 2 * sizeof(float));

		Rendering::VertexBufferLayout* bufferLayout = new Rendering::VertexBufferLayout();
		(*bufferLayout).Push<float>(2);

		_vertexArray.AddBuffer(*vertexBuffer, *bufferLayout);

		_shader.Bind();
		_shader.SetUniform4f("u_Color", 1.0f, 0.0f, 0.0f, 1.0f);
	}

	Object2D::~Object2D()
	{
	}
	
	void Object2D::Render()
	{
		Rendering::Renderer::Draw(_vertexArray, _indexBuffer, _shader);
	}
}