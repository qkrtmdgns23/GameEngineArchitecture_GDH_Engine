#include "texture.h"
#include "file_manager.h"

namespace object {
	namespace component {
		Texture::Texture(std::string texture_path
			, TextureDimensionalType type_of_texture
			, TextureAlphaType alpha_data_type)
		{
			this->texture_width_ = 0;
			this->texture_height_ = 0;
			this->texture_nr_channels_ = 0;
			this->texture_id_ = 0;

			glGenTextures(1, &texture_id_);

			if (type_of_texture == TextureDimensionalType::k2D)
			{
				glBindTexture(GL_TEXTURE_2D, texture_id_);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			}
			else if (type_of_texture == TextureDimensionalType::k3D)
			{
				glBindTexture(GL_TEXTURE_2D, texture_id_);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			}

			if (type_of_texture == TextureDimensionalType::k2D)
			{
				system_2::FileManager::get_instance()->LoadTexture2D
				(texture_path, this->texture_width_, this->texture_height_,
				this->texture_nr_channels_, alpha_data_type);
			}
			else if (type_of_texture == TextureDimensionalType::k3D)
			{
				system_2::FileManager::get_instance()->LoadTexture2D
				(texture_path, this->texture_width_, this->texture_height_, 
				this->texture_nr_channels_, alpha_data_type);
			}

			SetActive();
		}

		Texture::Texture(const char* texture_path
			, TextureDimensionalType type_of_texture
			, TextureAlphaType alpha_data_type)
		{

			this->texture_width_ = 0;
			this->texture_height_ = 0;
			this->texture_nr_channels_ = 0;
			this->texture_id_ = 0;

			glGenTextures(1, &texture_id_);

			if (type_of_texture == TextureDimensionalType::k2D)
			{
				glBindTexture(GL_TEXTURE_2D, texture_id_);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			}
			else if (type_of_texture == TextureDimensionalType::k3D)
			{
				glBindTexture(GL_TEXTURE_2D, texture_id_);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			}

			if (type_of_texture == TextureDimensionalType::k2D)
			{
				system_2::FileManager::get_instance()->LoadTexture2D
				(texture_path, this->texture_width_, this->texture_height_,
					this->texture_nr_channels_, alpha_data_type);
			}
			else if (type_of_texture == TextureDimensionalType::k3D)
			{
				system_2::FileManager::get_instance()->LoadTexture2D
				(texture_path, this->texture_width_, this->texture_height_,
					this->texture_nr_channels_, alpha_data_type);
			}

			SetActive();
		}
	}	// namespace component
}	// namespace object