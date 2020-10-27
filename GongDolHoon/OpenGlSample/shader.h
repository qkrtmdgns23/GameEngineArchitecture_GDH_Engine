#ifndef GDH_ENGINE_SHADER_H
#define GDH_ENGINE_SHADER_H

#include <string>

// library
#include "include/GL/glew.h"	
#include "glm/glm.hpp"

namespace gdh_engine {
	namespace object {
		class Shader;

		class Shader
		{
		public:
			Shader(const char* vertex_path, const char* fragment_path);
			Shader(std::string vertex_path, std::string fragment_path);

			~Shader();

			void UseShader();
			void UnuseShader();

			// this is not setter function.
			void SetBooleanDataTypeUniformVariable(const std::string& name, bool value) const;
			void SetBooleanDataTypeUniformVariable(const char* name, bool value) const;
			void SetIntegerDataTypeUniformVariable(const std::string& name, int value) const;
			void SetIntegerDataTypeUniformVariable(const char* name, int value) const;
			void SetFloatDataTypeUniformVariable(const std::string& name, float value) const;
			void SetFloatDataTypeUniformVariable(const char* name, float value) const;
			void SetVector2TypeUniformVariable(const std::string& name, glm::vec2& value) const;
			void SetVector2TypeUniformVariable(const char* name, glm::vec2& value) const;
			void SetVector2TypeUniformVariable(const std::string& name, float x, float y) const;
			void SetVector2TypeUniformVariable(const char* name, float x, float y) const;
			void SetVector3TypeUniformVariable(const std::string& name, glm::vec3& value) const;
			void SetVector3TypeUniformVariable(const char* name, glm::vec3& value) const;
			void SetVector3TypeUniformVariable(const std::string& name, float x, float y, float z) const;
			void SetVector3TypeUniformVariable(const char* name, float x, float y, float z) const;
			void SetVector4TypeUniformVariable(const std::string& name, glm::vec4& value) const;
			void SetVector4TypeUniformVariable(const char* name, glm::vec4& value) const;
			void SetVector4TypeUniformVariable(const std::string& name, 
				float x, float y, float z, float w) const;
			void SetVector4TypeUniformVariable(const char* name,
				float x, float y, float z, float w) const;
			void SetMatrix2TypeUniformVariable(const std::string& name, const glm::mat2& mat) const;
			void SetMatrix2TypeUniformVariable(const char* name, const glm::mat2& mat) const;
			void SetMatrix3TypeUniformVariable(const std::string& name, const glm::mat3& mat) const;
			void SetMatrix3TypeUniformVariable(const char* name, const glm::mat3& mat) const;
			void SetMatrix4TypeUniformVariable(const std::string& name, const glm::mat4& mat) const;
			void SetMatrix4TypeUniformVariable(const char* name, const glm::mat4& mat) const;

			GLuint get_shader_program_id() const
			{
				return shader_program_identity_;
			}
		private:
			GLuint shader_program_identity_;
		};
	}	// namespace object
}	// namespace gdh_engine

#endif // GDH_ENGINE_SHADER_H