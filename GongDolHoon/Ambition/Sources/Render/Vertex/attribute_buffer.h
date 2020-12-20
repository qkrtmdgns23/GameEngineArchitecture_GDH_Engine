#ifndef __AMBITION_ATTRIBUTE_BUFFER__
#define __AMBITION_ATTRIBUTE_BUFFER__

#include "framework.h"
#include "pch.h"
#include "Ibuffer.h"

namespace ambition
{
	namespace render
	{
		AMBITION_CLASS AttributeBuffer final: public Buffer
		{
		public:
			AttributeBuffer(float* data, GLuint attribute, GLuint attribute_size, GLuint size);
			AttributeBuffer(const AttributeBuffer& other) = delete;
			~AttributeBuffer();
		public:
			inline void				SetBind(bool whether) const override
			{
				if (whether == true)
				{
					glBindBuffer(GL_ARRAY_BUFFER, id_);
				}
				else
				{
					glBindBuffer(GL_ARRAY_BUFFER, NULL);
				}
			}
			inline virtual GLuint	GetAttribute() const override
			{
				return attribute_;
			}
			inline virtual GLuint	GetAttributeSize() const override
			{
				return vao_offset_;
			}
		private:
			GLuint attribute_;
			GLuint attribute_size_;
			static GLuint id_index_;
			static GLuint vao_offset_;
		};
	}		// namespace render
}			// namespace ambition

#endif		// __AMBITION_BUFFER__