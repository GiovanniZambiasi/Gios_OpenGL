#include "VertexArray.h"
#include "OpenGLUtilities.h"
#include "VertexBufferLayout.h"
#include "../Debug.h"

namespace Gio::Rendering
{
	VertexArray::VertexArray()
	{
		GLCall(glGenVertexArrays(1, &_rendererID));
	}

	VertexArray::~VertexArray()
	{
		GLCall(glDeleteVertexArrays(1, &_rendererID));
	}

	void VertexArray::AddBuffer(const VertexBuffer& vertexBuffer, const VertexBufferLayout& layout)
	{
		Bind();

		vertexBuffer.Bind();

		const auto& elements = layout.GetElements();

		unsigned int offset = 0;

		for (unsigned int i = 0; i < elements.size(); i++)
		{
			const auto& element = elements[i];

			GLCall(glEnableVertexAttribArray(i));
			GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void*)offset));

			offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
		}
	}

	void VertexArray::Bind() const
	{
		GLCall(glBindVertexArray(_rendererID));
	}

	void VertexArray::UnBind() const
	{
		GLCall(glBindVertexArray(0));
	}
}