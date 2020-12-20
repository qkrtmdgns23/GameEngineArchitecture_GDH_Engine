#ifndef __AMBITION_INDEX_BUFFER__
#define __AMBITION_INDEX_BUFFER__

#include "framework.h"
#include "Ibuffer.h"

namespace ambition
{
	namespace render
	{
		AMBITION_CLASS IndexBuffer final: public Buffer
		{
		public:
			IndexBuffer(GLuint* data, GLuint size);
			IndexBuffer(const IndexBuffer& other) = delete;
			~IndexBuffer();
		public:
			inline void		SetBind(bool whether) const override
			{
				if (whether == true)
				{
					glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_);
				}
				else
				{
					glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NULL);
				}
			}
			virtual GLuint	GetAttribute() const override { return NULL; }
			virtual GLuint	GetAttributeSize() const override { return NULL; }
		};
	}		// namespace render
}			// namespace ambition

#endif		// __AMBITION_INDEX_BUFFER__