#include "attribute_buffer.h"

namespace ambition
{
	namespace render
	{
		GLuint AttributeBuffer::vao_offset_ = 0;
		GLuint AttributeBuffer::id_index_ = 0;

		AttributeBuffer::AttributeBuffer(float* data, GLuint attribute, GLuint attribute_size, GLuint size)
			: Buffer(), attribute_(attribute), attribute_size_(attribute_size)
		{
			size_ = size;
			vao_offset_ += attribute_size_;
			id_ = ++id_index_;
			glGenBuffers(1, &id_);
			SetBind(true);
			glBufferData(GL_ARRAY_BUFFER, size * sizeof(data), data, GL_STATIC_DRAW);
		}	

		AttributeBuffer::~AttributeBuffer()
		{
			glDeleteBuffers(1, &id_);
		}
	}	// namespace render
}		// namespace ambition