#include <iostream>
#include <fstream>
#include <sstream>

#include "include/GL/glew.h"		
#include "include/GLFW/glfw3.h" 
#define STB_IMAGE_IMPLEMENTATION
#include "include/stb/stb_image.h"

#include "file_manager.h"

namespace gdh_system {
	FileManager* FileManager::instance_ = nullptr;

	GLuint FileManager::LoadAndCreateShader(const char* vertex_path, const char* fragment_path)
	{
		printf("GONG_DOL_HOON_CUSTOM_ENGINE [SHADER_LOADING]: %s, %s\n", vertex_path, fragment_path);

		GLuint vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragment_shader_id = glCreateShader(GL_FRAGMENT_SHADER);

		std::string vertex_shader_code;
		std::ifstream vertex_shader_stream(vertex_path, std::ios::in);
		if (vertex_shader_stream.is_open()) {
			std::stringstream sstr;
			sstr << vertex_shader_stream.rdbuf();
			vertex_shader_code = sstr.str();
			vertex_shader_stream.close();
		}
		else {
			printf("Cannot reading \"%s\" file. Confirm the file path.\n", vertex_path);
			getchar();
			return 0;
		}

		std::string fragment_shader_code;
		std::ifstream fragment_shader_stream(fragment_path, std::ios::in);
		if (fragment_shader_stream.is_open()) {
			std::stringstream sstr;
			sstr << fragment_shader_stream.rdbuf();
			fragment_shader_code = sstr.str();
			fragment_shader_stream.close();
		}
		else {
			printf("Cannot reading \"%s\" file. Confirm the file path.\n", fragment_path);
			getchar();
			return 0;
		}

		GLint _result = GL_FALSE;
		int _info_log_length;

		char const* _vertex_source_pointer = vertex_shader_code.c_str();
		glShaderSource(vertex_shader_id, 1, &_vertex_source_pointer, NULL);
		glCompileShader(vertex_shader_id);

		glGetShaderiv(vertex_shader_id, GL_COMPILE_STATUS, &_result);
		glGetShaderiv(vertex_shader_id, GL_INFO_LOG_LENGTH, &_info_log_length);
		if (_info_log_length > 0) {
			std::vector<char> VertexShaderErrorMessage(_info_log_length + 1);
			glGetShaderInfoLog(vertex_shader_id, _info_log_length, NULL, &VertexShaderErrorMessage[0]);
			printf("%s\n", &VertexShaderErrorMessage[0]);
		}

		char const* fragment_source_pointer = fragment_shader_code.c_str();
		glShaderSource(fragment_shader_id, 1, &fragment_source_pointer, NULL);
		glCompileShader(fragment_shader_id);

		glGetShaderiv(fragment_shader_id, GL_COMPILE_STATUS, &_result);
		glGetShaderiv(fragment_shader_id, GL_INFO_LOG_LENGTH, &_info_log_length);
		if (_info_log_length > 0) {
			std::vector<char> FragmentShaderErrorMessage(_info_log_length + 1);
			glGetShaderInfoLog(fragment_shader_id, _info_log_length, NULL, &FragmentShaderErrorMessage[0]);
			printf("%s\n", &FragmentShaderErrorMessage[0]);
		}

		GLuint _program_id = glCreateProgram();
		glAttachShader(_program_id, vertex_shader_id);
		glAttachShader(_program_id, fragment_shader_id);
		glLinkProgram(_program_id);

		glGetProgramiv(_program_id, GL_LINK_STATUS, &_result);
		glGetProgramiv(_program_id, GL_INFO_LOG_LENGTH, &_info_log_length);
		if (_info_log_length > 0) {
			std::vector<char> _program_error_message(_info_log_length + 1);
			glGetProgramInfoLog(_program_id, _info_log_length, NULL, &_program_error_message[0]);
			printf("%s\n", &_program_error_message[0]);
		}

		glDetachShader(_program_id, vertex_shader_id);
		glDetachShader(_program_id, fragment_shader_id);

		glDeleteShader(vertex_shader_id);
		glDeleteShader(fragment_shader_id);

		return _program_id;
	}
	GLuint FileManager::LoadAndCreateShader(std::string vertex_path, std::string fragment_path)
	{
		printf("GONG_DOL_HOON_CUSTOM_ENGINE [SHADER_LOADING]: %s, %s\n", vertex_path.c_str(), fragment_path.c_str());

		GLuint vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragment_shader_id = glCreateShader(GL_FRAGMENT_SHADER);

		std::string vertex_shader_code;
		std::ifstream vertex_shader_stream(vertex_path, std::ios::in);
		if (vertex_shader_stream.is_open()) {
			std::stringstream sstr;
			sstr << vertex_shader_stream.rdbuf();
			vertex_shader_code = sstr.str();
			vertex_shader_stream.close();
		}
		else {
			printf("Cannot reading \"%s\" file. Confirm the file path.\n", vertex_path.c_str());
			getchar();
			return 0;
		}

		std::string fragment_shader_code;
		std::ifstream fragment_shader_stream(fragment_path, std::ios::in);
		if (fragment_shader_stream.is_open()) {
			std::stringstream sstr;
			sstr << fragment_shader_stream.rdbuf();
			fragment_shader_code = sstr.str();
			fragment_shader_stream.close();
		}
		else {
			printf("Cannot reading \"%s\" file. Confirm the file path.\n", fragment_path.c_str());
			getchar();
			return 0;
		}

		GLint result = GL_FALSE;
		int info_log_length;

		char const* vertex_source_pointer = vertex_shader_code.c_str();
		glShaderSource(vertex_shader_id, 1, &vertex_source_pointer, NULL);
		glCompileShader(vertex_shader_id);

		glGetShaderiv(vertex_shader_id, GL_COMPILE_STATUS, &result);
		glGetShaderiv(vertex_shader_id, GL_INFO_LOG_LENGTH, &info_log_length);
		if (info_log_length > 0) {
			std::vector<char> VertexShaderErrorMessage(info_log_length + 1);
			glGetShaderInfoLog(vertex_shader_id, info_log_length, NULL, &VertexShaderErrorMessage[0]);
			printf("%s\n", &VertexShaderErrorMessage[0]);
		}

		char const* fragment_source_pointer = fragment_shader_code.c_str();
		glShaderSource(fragment_shader_id, 1, &fragment_source_pointer, NULL);
		glCompileShader(fragment_shader_id);

		glGetShaderiv(fragment_shader_id, GL_COMPILE_STATUS, &result);
		glGetShaderiv(fragment_shader_id, GL_INFO_LOG_LENGTH, &info_log_length);
		if (info_log_length > 0) {
			std::vector<char> FragmentShaderErrorMessage(info_log_length + 1);
			glGetShaderInfoLog(fragment_shader_id, info_log_length, NULL, &FragmentShaderErrorMessage[0]);
			printf("%s\n", &FragmentShaderErrorMessage[0]);
		}

		GLuint program_id = glCreateProgram();
		glAttachShader(program_id, vertex_shader_id);
		glAttachShader(program_id, fragment_shader_id);
		glLinkProgram(program_id);

		glGetProgramiv(program_id, GL_LINK_STATUS, &result);
		glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &info_log_length);
		if (info_log_length > 0) {
			std::vector<char> program_error_message(info_log_length + 1);
			glGetProgramInfoLog(program_id, info_log_length, NULL, &program_error_message[0]);
			printf("%s\n", &program_error_message[0]);
		}

		glDetachShader(program_id, vertex_shader_id);
		glDetachShader(program_id, fragment_shader_id);

		glDeleteShader(vertex_shader_id);
		glDeleteShader(fragment_shader_id);

		return program_id;
	}
	GLuint FileManager::Load3DModelFromObj(const char* obj_path,
		std::vector<glm::vec3>& out_vertices, std::vector<glm::vec2>& out_uvs, std::vector<glm::vec3>& out_normals, unsigned int* num_of_vertices)
	{
		printf("GONG_DOL_HOON_CUSTOM_ENGINE [OBJ_LOADING]: %s\n", obj_path);

		std::vector<unsigned int> vertex_indices, uv_indices, normal_indices;
		std::vector<glm::vec3> temp_sphere_vertices;
		std::vector<glm::vec2> temp_sphere_uvs;
		std::vector<glm::vec3> temp_sphere_normals;


		FILE* file = fopen(obj_path, "r");
		if (file == NULL) {
			printf("Impossible to open the file ! Are you in the right path ? See Tutorial 1 for details\n");
			getchar();
			return false;
		}

		while (1) {

			char line_header[128];
			// read the first word of the line
			int res = fscanf(file, "%s", line_header);
			if (res == EOF)
				break; // EOF = End Of File. Quit the loop.

			// else : parse lineHeader

			if (strcmp(line_header, "v") == 0) {
				glm::vec3 vertex;
				fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
				temp_sphere_vertices.push_back(vertex);
			}
			else if (strcmp(line_header, "vt") == 0) {
				glm::vec2 uv;
				fscanf(file, "%f %f\n", &uv.x, &uv.y);
				uv.y = -uv.y; // Invert V coordinate since we will only use DDS texture, which are inverted. Remove if you want to use TGA or BMP loaders.
				temp_sphere_uvs.push_back(uv);
			}
			else if (strcmp(line_header, "vn") == 0) {
				glm::vec3 _normal;
				fscanf(file, "%f %f %f\n", &_normal.x, &_normal.y, &_normal.z);
				temp_sphere_normals.push_back(_normal);
			}
			else if (strcmp(line_header, "f") == 0) {
				std::string vertex1, vertex2, vertex3;
				unsigned int vertex_index[3], uv_index[3], normal_index[3];
				int _matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertex_index[0], &uv_index[0], &normal_index[0], &vertex_index[1], &uv_index[1], &normal_index[1], &vertex_index[2], &uv_index[2], &normal_index[2]);
				if (_matches != 9) {
					printf("File can't be read by our simple parser :-( Try exporting with other options\n");
					fclose(file);
					return false;
				}
				vertex_indices.push_back(vertex_index[0]);
				vertex_indices.push_back(vertex_index[1]);
				vertex_indices.push_back(vertex_index[2]);
				uv_indices.push_back(uv_index[0]);
				uv_indices.push_back(uv_index[1]);
				uv_indices.push_back(uv_index[2]);
				normal_indices.push_back(normal_index[0]);
				normal_indices.push_back(normal_index[1]);
				normal_indices.push_back(normal_index[2]);
			}
			else {
				// Probably a comment, eat up the rest of the line
				char _stupid_buffer[1000];
				fgets(_stupid_buffer, 1000, file);
			}

		}

		*num_of_vertices = static_cast<unsigned int>(vertex_indices.size());

		// For each vertex of each triangle
		for (unsigned int i = 0; i < vertex_indices.size(); i++) {

			// Get the indices of its attributes
			unsigned int vertex_index = vertex_indices[i];
			unsigned int uv_index = uv_indices[i];
			unsigned int normal_index = normal_indices[i];

			// Get the attributes thanks to the index
			glm::vec3 vertex = temp_sphere_vertices[vertex_index - 1];
			glm::vec2 uv = temp_sphere_uvs[uv_index - 1];
			glm::vec3 normal = temp_sphere_normals[normal_index - 1];

			// Put the attributes in buffers
			out_vertices.push_back(vertex);
			out_uvs.push_back(uv);
			out_normals.push_back(normal);
		}
		fclose(file);

		return true;
	}
	GLuint FileManager::Load3DModelFromObj(std::string obj_path,
		std::vector<glm::vec3>& out_vertices, std::vector<glm::vec2>& out_uvs, std::vector<glm::vec3>& out_normals, unsigned int* num_of_vertices)
	{
		printf("GONG_DOL_HOON_CUSTOM_ENGINE [OBJ_LOADING]: %s\n", obj_path.c_str());

		std::vector<unsigned int> vertex_indices, uv_indices, normal_indices;
		std::vector<glm::vec3> temp_sphere_vertices;
		std::vector<glm::vec2> temp_sphere_uvs;
		std::vector<glm::vec3> temp_sphere_normals;


		FILE* file = fopen(obj_path.c_str(), "r");
		if (file == NULL) {
			printf("Impossible to open the file ! Are you in the right path ? See Tutorial 1 for details\n");
			getchar();
			return false;
		}

		while (1) {

			char line_header[128];
			// read the first word of the line
			int res = fscanf(file, "%s", line_header);
			if (res == EOF)
				break; // EOF = End Of File. Quit the loop.

			// else : parse lineHeader

			if (strcmp(line_header, "v") == 0) {
				glm::vec3 vertex;
				fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
				temp_sphere_vertices.push_back(vertex);
			}
			else if (strcmp(line_header, "vt") == 0) {
				glm::vec2 uv;
				fscanf(file, "%f %f\n", &uv.x, &uv.y);
				uv.y = -uv.y; // Invert V coordinate since we will only use DDS texture, which are inverted. Remove if you want to use TGA or BMP loaders.
				temp_sphere_uvs.push_back(uv);
			}
			else if (strcmp(line_header, "vn") == 0) {
				glm::vec3 _normal;
				fscanf(file, "%f %f %f\n", &_normal.x, &_normal.y, &_normal.z);
				temp_sphere_normals.push_back(_normal);
			}
			else if (strcmp(line_header, "f") == 0) {
				std::string vertex1, vertex2, vertex3;
				unsigned int vertex_index[3], uv_index[3], normal_index[3];
				int _matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertex_index[0], &uv_index[0], &normal_index[0], &vertex_index[1], &uv_index[1], &normal_index[1], &vertex_index[2], &uv_index[2], &normal_index[2]);
				if (_matches != 9) {
					printf("File can't be read by our simple parser :-( Try exporting with other options\n");
					fclose(file);
					return false;
				}
				vertex_indices.push_back(vertex_index[0]);
				vertex_indices.push_back(vertex_index[1]);
				vertex_indices.push_back(vertex_index[2]);
				uv_indices.push_back(uv_index[0]);
				uv_indices.push_back(uv_index[1]);
				uv_indices.push_back(uv_index[2]);
				normal_indices.push_back(normal_index[0]);
				normal_indices.push_back(normal_index[1]);
				normal_indices.push_back(normal_index[2]);
			}
			else {
				// Probably a comment, eat up the rest of the line
				char _stupid_buffer[1000];
				fgets(_stupid_buffer, 1000, file);
			}

		}

		*num_of_vertices = static_cast<unsigned int>(vertex_indices.size());

		// For each vertex of each triangle
		for (unsigned int i = 0; i < vertex_indices.size(); i++) {

			// Get the indices of its attributes
			unsigned int _vertex_index = vertex_indices[i];
			unsigned int _uv_index = uv_indices[i];
			unsigned int _normal_index = normal_indices[i];

			// Get the attributes thanks to the index
			glm::vec3 vertex = temp_sphere_vertices[_vertex_index - 1];
			glm::vec2 uv = temp_sphere_uvs[_uv_index - 1];
			glm::vec3 normal = temp_sphere_normals[_normal_index - 1];

			// Put the attributes in buffers
			out_vertices.push_back(vertex);
			out_uvs.push_back(uv);
			out_normals.push_back(normal);

		}
		fclose(file);

		return true;
	}
	void FileManager::LoadTexture2D(const char* texture_path, int texture_width, int texture_height, int texture_nr_channels
		, object::TextureAlphaType alpha_data_type)
	{
		unsigned char* data = stbi_load(texture_path, &texture_width, &texture_height, &texture_nr_channels, 0);
		stbi_set_flip_vertically_on_load(true);
		if (data && alpha_data_type == object::TextureAlphaType::kRGB)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture_width, texture_height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
			std::cout << "Load Succeed: " << texture_path << std::endl;
		}
		else if (data && alpha_data_type == object::TextureAlphaType::kRGBA)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture_width, texture_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
			std::cout << "Load Succeed: " << texture_path << std::endl;
		}
		else
		{
			std::cout << "Failed to load texture: " << texture_path << std::endl;
		}
		stbi_image_free(data);
	}
	void FileManager::LoadTexture2D(std::string texture_path, int texture_width, int texture_height, int texture_nr_channels
		, object::TextureAlphaType alpha_data_type)
	{
		unsigned char* data = stbi_load(texture_path.c_str(), &texture_width, &texture_height, &texture_nr_channels, 0);
		stbi_set_flip_vertically_on_load(true);
		if (data && alpha_data_type == object::TextureAlphaType::kRGB)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture_width, texture_height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
			std::cout << "Load Succeed: " << texture_path << std::endl;
		}
		else if (data && alpha_data_type == object::TextureAlphaType::kRGBA)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture_width, texture_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
			std::cout << "Load Succeed: " << texture_path << std::endl;
		}
		else
		{
			std::cout << "Failed to load texture: " << texture_path << std::endl;
		}
		stbi_image_free(data);
	}

}	// namespace gdh_system