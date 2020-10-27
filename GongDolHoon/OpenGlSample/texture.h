#ifndef GDH_ENGINE_TEXTURE_H
#define GDH_ENGINE_TEXTURE_H

#include <string>

// library
#include "include/GL/glew.h"	

#include "interface_component.h"

namespace gdh_engine {
	namespace object {
		enum class TextureType;

		class Texture : public InterfaceComponent
		{
		public:
			Texture(std::string texture_path, TextureType type_of_texture, TextureType alpha_data_type);
			Texture(const char* texture_path, TextureType type_of_texture, TextureType alpha_data_type);
			~Texture() {}

			virtual void SetActive() final;
			virtual void SetUnActive() final;

			bool get_is_texture_active() const
			{
				return is_texture_active_;
			}

			GLuint get_texture_id() const
			{
				if(is_texture_active_)
				{
					return texture_id_;
				}
				else
				{
					return 0;
				}
			}

		private:
			GLuint texture_id_;

			int texture_width_;
			int texture_height_;
			int texture_nr_channels_;

			bool is_texture_active_;
		};

		enum class TextureType
		{
			k2DimensionalTexture = 0,
			k3DimensionalTexture,
			kRGBTexture,
			kRGBATexture,
		};

	} // namespace object
} // namespace gdh_engine

#endif // GDH_ENGINE_TEXTURE_H