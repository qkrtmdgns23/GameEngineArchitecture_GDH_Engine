// custom header
#include "texture.h"
#include "file_manager.h"

namespace gdh_engine {
	namespace object {
		Texture::Texture(std::string texture_path, TextureType type_of_texture, TextureType alpha_data_type)
		{
			this->texture_width_ = 0;
			this->texture_height_ = 0;
			this->texture_nr_channels_ = 0;
			this->texture_id_ = 0;

			glGenTextures(1, &texture_id_);

			if (type_of_texture == TextureType::k2DimensionalTexture)
			{
				glBindTexture(GL_TEXTURE_2D, texture_id_);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			}
			else if (type_of_texture == TextureType::k3DimensionalTexture)
			{
				glBindTexture(GL_TEXTURE_2D, texture_id_);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			}

			if (type_of_texture == TextureType::k2DimensionalTexture)
			{
				gdh_engine::manager::file::FileManager::get_instance()->LoadTexture2D
				(texture_path, this->texture_width_, this->texture_height_, this->texture_nr_channels_, alpha_data_type);
			}
			else if (type_of_texture == TextureType::k3DimensionalTexture)
			{
				gdh_engine::manager::file::FileManager::get_instance()->LoadTexture2D
				(texture_path, this->texture_width_, this->texture_height_, this->texture_nr_channels_, alpha_data_type);
			}

			SetActive();
		}

		Texture::Texture(const char* texture_path, TextureType type_of_texture, TextureType alpha_data_type)
		{
			this->texture_width_ = 0;
			this->texture_height_ = 0;
			this->texture_nr_channels_ = 0;

			glGenTextures(1, &texture_id_);

			if (type_of_texture == TextureType::k2DimensionalTexture)
			{
				glBindTexture(GL_TEXTURE_2D, texture_id_);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			}
			else if (type_of_texture == TextureType::k3DimensionalTexture)
			{
				glBindTexture(GL_TEXTURE_2D, texture_id_);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			}

			if (type_of_texture == TextureType::k2DimensionalTexture)
			{
				gdh_engine::manager::file::FileManager::get_instance()->LoadTexture2D
				(texture_path, this->texture_width_, this->texture_height_, this->texture_nr_channels_, alpha_data_type);
			}
			else if (type_of_texture == TextureType::k3DimensionalTexture)
			{
				gdh_engine::manager::file::FileManager::get_instance()->LoadTexture2D
				(texture_path, this->texture_width_, this->texture_height_, this->texture_nr_channels_, alpha_data_type);
			}

			SetActive();
		}
		void Texture::SetActive()
		{
			is_texture_active_ = true;
		}

		void Texture::SetUnActive()
		{
			is_texture_active_ = false;
		}
	}	// namespace object
}	// namespace gdh_engine