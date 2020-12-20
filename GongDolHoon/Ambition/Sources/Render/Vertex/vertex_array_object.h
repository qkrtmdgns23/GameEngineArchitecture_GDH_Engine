#ifndef __AMBITION_VERTEX_ARRAY_OBJECT__
#define __AMBITION_VERTEX_ARRAY_OBJECT__

#include "framework.h"	
#include "pch.h"
#include "Sources/Render/Vertex/Ibuffer.h"
#include "Sources/Render/Vertex/index_buffer.h"

namespace ambition
{
	namespace render
	{
		AMBITION_CLASS VertexArrayObject
		{
		public:
			VertexArrayObject();
			~VertexArrayObject();
		public:
			void		AddBuffer(std::shared_ptr<Buffer> buffer, int index);
			inline void SetBind(bool whether) const
			{
				if (whether == true)
				{
					glBindVertexArray(id_);
				}
				else
				{
					glBindVertexArray(NULL);
				}
			}
		private:
			GLuint id_;					
			std::list<std::shared_ptr<Buffer>> buffers_;
		};
	}		// namespace render
}			// namespace ambition

#endif		// __AMBITION_VERTEX_ARRAY_OBJECT__