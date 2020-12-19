#ifndef __AMBITION_SHADER__
#define __AMBITION_SHADER__

#include "framework.h"
#include "pch.h"

namespace ambition
{
	namespace render
	{
		AMBITION_CLASS Shader
		{
		public:
			Shader(const char* vertex_path, const char* fragment_path);
			Shader(const Shader& other);
			virtual ~Shader() = default;

			inline void SetUse(bool whether) const
			{	
				if (whether == true)
				{
					glUseProgram(id_);
				}
				else
				{
					glUseProgram(NULL);
				}
			}
		private:
			void CheckCompileError(GLuint shader, const char* type) const;
		private:
			const char* vertex_content_;
			const char* fragment_content_;
			GLuint id_;
		};
	}		// namespace render
}			// namespace ambition

#endif		// __AMBITION_SHADER__
