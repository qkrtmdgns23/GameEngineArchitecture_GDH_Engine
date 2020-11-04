#ifndef GDH_ENGINE_FILE_MANAGER_H
#define GDH_ENGINE_FILE_MANAGER_H
#include <vector>
#include "glm/glm.hpp"

#include "loader_params.h"

namespace gdh_system {
	class FileManager
	{
	#pragma region SINGLETON_PATTERN
	public:
		static FileManager* get_instance()
		{
			if (instance_ == nullptr)
			{
				instance_ = new FileManager();
			}

			return instance_;
		}
		FileManager(const FileManager& other) = delete;
		~FileManager() = default;
	private:
		FileManager() = default;
		static FileManager* instance_;

	#pragma endregion
	public:
		GLuint LoadAndCreateShader(const char* vertex_path, const char* fragment_path);
		GLuint LoadAndCreateShader(std::string vertex_path, std::string fragment_path);
		GLuint Load3DModelFromObj(const char* obj_path, std::vector<glm::vec3>& out_vertices,
			std::vector<glm::vec2>& out_uvs, std::vector<glm::vec3>& out_normals, 
			unsigned int* num_of_vertices);
		GLuint Load3DModelFromObj(std::string obj_path, std::vector<glm::vec3>& out_vertices,
			std::vector<glm::vec2>& out_uvs, std::vector<glm::vec3>& out_normals, 
			unsigned int* num_of_vertices);
		void LoadTexture2D(const char* texture_path, int texture_width, int texture_height, 
		int texture_nr_channels, object::TextureAlphaType alpha_data_type);
		void LoadTexture2D(std::string texture_path, int texture_width, int texture_height, 
		int texture_nr_channels, object::TextureAlphaType alpha_data_type);
	};
} // namespace gdh_system
#endif // GDH_ENGINE_FILE_MANAGER