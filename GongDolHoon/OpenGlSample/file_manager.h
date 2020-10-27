#ifndef GDH_ENGINE_FILE_MANAGER_H
#define GDH_ENGINE_FILE_MANAGER_H

#include <vector>

// library
#include "glm/glm.hpp"

// custom header
#include "texture.h"

namespace gdh_engine {
	namespace manager {
		namespace file {
			// InputManager class was written as singleton pattern.
			class FileManager
			{
			public:
				GLuint LoadAndCreateShader(const char* vertex_path, const char* fragment_path);
				GLuint LoadAndCreateShader(std::string vertex_path, std::string fragment_path);
				GLuint Load3DModelFromObj(const char* obj_path,	std::vector<glm::vec3>& out_vertices, 
					std::vector<glm::vec2>& out_uvs, std::vector<glm::vec3>& out_normals, unsigned int* num_of_vertices);
				GLuint Load3DModelFromObj(std::string obj_path, std::vector<glm::vec3>& out_vertices, 
					std::vector<glm::vec2>& out_uvs, std::vector<glm::vec3>& out_normals, unsigned int* num_of_vertices);
				void LoadTexture2D(const char* texture_path, int texture_width, int texture_height, int texture_nr_channels,
					object::TextureType alpha_data_type);
				void LoadTexture2D(std::string texture_path, int texture_width, int texture_height, int texture_nr_channels,
					object::TextureType alpha_data_type);

				static FileManager* get_instance()
				{
					if (instance_ == nullptr)
					{
						instance_ = new FileManager();
					}

					return instance_;
				}

			private:
				FileManager() {}
				FileManager(const FileManager& other) {}
				~FileManager() {}

				static FileManager* instance_;
			};
		} // namespace file
	} // namespace manager
} // namespace gdh_engine

#endif // GDH_ENGINE_FILE_MANAGER