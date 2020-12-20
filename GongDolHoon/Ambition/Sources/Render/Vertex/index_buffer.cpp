#include "index_buffer.h"

namespace ambition
{
	namespace render
	{
		IndexBuffer::IndexBuffer(GLuint* data, GLuint size)
			: Buffer()
		{
			id_ = 0;
			size_ = size;
			glGenBuffers(1, &id_);
			SetBind(true);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, size_ * sizeof(data), data, GL_STATIC_DRAW);
		}

		IndexBuffer::~IndexBuffer()
		{
			glDeleteBuffers(1, &id_);
		}
	}	// namespace render
}		// namespace ambition