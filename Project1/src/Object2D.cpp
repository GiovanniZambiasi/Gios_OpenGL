#include "Object2D.h"
#include "Renderer.h"
#include "VertexBuffer.h"

namespace Gio 
{
	Object2D::Object2D(float vertices[], unsigned int indices[])
		:	_indexBuffer(indices, 6)
		, _vertexBuffer(vertices, 4 * 2 * sizeof(float))
		,	_shader(Rendering::Shader("res/Shaders/Basic.shader"))
	{
		Rendering::VertexBufferLayout* bufferLayout = new Rendering::VertexBufferLayout();
		(*bufferLayout).Push<float>(2);

		_vertexArray.AddBuffer(_vertexBuffer, *bufferLayout);

		_shader.Bind();
		_shader.SetUniform4f("u_Color", 1.0f, 0.0f, 0.0f, 1.0f);
	}

	Object2D::~Object2D()
	{
	}
	
	void Object2D::Render()
	{
		glColor3f(1.0f, 1.0f, 0.0f);
		
		glBegin(GL_TRIANGLES);

		glVertex3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, 0.0f);
		glVertex3f(0.0f, 1.0f, 0.0f);
		
		glEnd();
		//glPushMatrix();
		//glTranslatef(10.0f, 1.0f, 0.0f);

		//_vertexBuffer.Translate(Vector2(1.0f, 0.0f));
		
		//Renderer::Draw(_vertexArray, _indexBuffer, _shader);
		//glPopMatrix();
	}
}