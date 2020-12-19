#include "shader.h"
#include "Sources/Input/file_reader.h"

namespace ambition
{
	namespace render
	{
		Shader::Shader(const char* vertex_path, const char* fragment_path)
			: id_(NULL)
		{
			std::string temp_vertex_content = input::FileReader::GetInstance()->ReadFromFile(vertex_path);
			std::string temp_fragment_content = input::FileReader::GetInstance()->ReadFromFile(fragment_path);

			vertex_content_ = temp_vertex_content.c_str();
			fragment_content_ = temp_fragment_content.c_str();

			GLuint vertex, fragment;
			vertex = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(vertex, 1, &vertex_content_, NULL);
			glCompileShader(vertex);
			CheckCompileError(vertex, "VERTEX");

			fragment = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(fragment, 1, &fragment_content_, NULL);
			glCompileShader(fragment);
			CheckCompileError(fragment, "FRAGMENT");

			id_ = glCreateProgram();
			glAttachShader(id_, vertex);
			glAttachShader(id_, fragment);
			glLinkProgram(id_);
			CheckCompileError(id_, "PROGRAM");

			glDeleteShader(vertex);
			glDeleteShader(fragment);
		}

		void Shader::CheckCompileError(GLuint shader, const char* type) const
		{
			GLint success = NULL;
			GLchar info_log[1024] = {NULL};

			if (type != "PROGRAM")
			{
				glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
				if (!success)
				{
					glGetShaderInfoLog(shader, 1024, NULL, info_log);
					std::cerr << "Shader compilation error occured." << std::endl;
					std::cerr << type << ": " << info_log << std::endl;
				}
			}
			else
			{
				glGetProgramiv(shader, GL_LINK_STATUS, &success);
				if (!success)
				{
					glGetProgramInfoLog(shader, 1024, NULL, info_log);
					std::cerr << "Shader linking error occured." << std::endl;
					std::cerr << type << ": " << info_log << std::endl;
				}
			}
		}
	}		// namespace render
}			// namespace ambition