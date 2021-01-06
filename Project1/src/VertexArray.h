#pragma once

#include "VertexBuffer.h"

class VertexBufferLayout;

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