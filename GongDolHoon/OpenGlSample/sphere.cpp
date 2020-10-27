#include "sphere.h"
#include "texture.h"

namespace gdh_engine {
	namespace object {
		namespace primitive {
			Sphere::Sphere() : VisibleObject("resource/shaders/sphere_vs.glsl",
				"resource/shaders/sphere_fs.glsl", "resource/jpg/container.jpg",
				"resource/obj/sphere.obj", object::TextureType::k2DimensionalTexture, 
				object::TextureType::kRGBTexture)
			{
				// Sphere.obj is too large. So, resized it smaller.
				this->SetObjectScale(glm::vec3(0.1f, 0.1f, 0.1f));
			}

			Sphere::~Sphere()
			{

			}
		} // namespace primitive
	} // namespace object
} // namespace gdh_engine