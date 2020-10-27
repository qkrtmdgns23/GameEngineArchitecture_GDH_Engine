#ifndef GDH_ENGINE_TEXTURE_H
#define GDH_ENGINE_TEXTURE_H

#include <string>
#include "include/GL/glew.h"	

#include "interface_component.h"
#include "loader_params.h"

namespace object {
	namespace component {
		class Texture : public InterfaceComponent
		{
		public:
		#pragma region CONSTRUCTOR_DESTRUCTOR
			Texture(std::string texture_path, TextureDimensionalType type_of_texture, 
				TextureAlphaType alpha_data_type);
			Texture(const char* texture_path, TextureDimensionalType type_of_texture,
				TextureAlphaType alpha_data_type);
			~Texture() {}
		#pragma endregion
			inline virtual void SetActive() final;
			inline virtual void SetUnActive() final;

			inline GLuint get_texture_id() const;

		private:
		#pragma region TEXTURE_INFORM
			GLuint texture_id_;
			int texture_width_;
			int texture_height_;
			int texture_nr_channels_;
		#pragma endregion
			bool is_texture_active_;
		};
		void Texture::SetActive()
		{
			is_texture_active_ = true;
		}

		void Texture::SetUnActive()
		{
			is_texture_active_ = false;
		}

		GLuint Texture::get_texture_id() const
		{
			if (is_texture_active_)
			{
				return texture_id_;
			}
			else
			{
				return 0;
			}
		}
	}	// namespace component
}	// namespace object
#endif // GDH_ENGINE_TEXTURE_H