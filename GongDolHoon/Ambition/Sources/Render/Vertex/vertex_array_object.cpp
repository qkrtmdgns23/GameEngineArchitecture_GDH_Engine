#include "vertex_array_object.h"

namespace ambition
{
	namespace render
	{
		VertexArrayObject::VertexArrayObject()
			: id_(0)
		{
			glGenVertexArrays(1, &id_);
		}

		VertexArrayObject::~VertexArrayObject()
		{
			glDeleteVertexArrays(1, &id_);
		}

		void VertexArrayObject::AddBuffer(std::shared_ptr<Buffer> buffer, int index)
		{
			buffers_.push_back(buffer);
			SetBind(true);
			buffer->SetBind(true);
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index, buffer->GetAttributeSize(), GL_FLOAT, GL_FALSE, buffer->GetAttributeSize() * sizeof(float), NULL);
			buffer->SetBind(false);
			SetBind(false);
		}
	}	// namespace render
}		// namespace ambition