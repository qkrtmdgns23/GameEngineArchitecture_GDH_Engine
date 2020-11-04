#ifndef GDH_ENGINE_LOADER_PARAMS_H
#define GDH_ENGINE_LOADER_PARAMS_H
#include <string>
#include "glm/glm.hpp"

namespace object {
	typedef struct TransformInformation
	{
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;
	}TransInform;

	typedef struct VertexInformation
	{
		glm::vec3 position;
		glm::vec2 texture_coordinate;
		glm::vec3 normal;
	}Vertex;

	enum class TextureDimensionalType
	{
		k2D = 0,
		k3D = 1,
	};

	enum class TextureAlphaType
	{
		kRGB = 0,
		kRGBA = 1,
	};

	class LoaderParams
	{
	public:
		LoaderParams(std::string vertex_path, std::string fragment_path,
			std::string texture_path, std::string obj_path, 
			TextureDimensionalType is_texture_3d, 
			TextureAlphaType is_texture_alpha,
			TransInform trans_inform = { glm::vec3(0.f),
			glm::vec3(0.f), glm::vec3(1.f) })
			: vertex_path_(vertex_path), fragment_path_(fragment_path)
			, texture_path_(texture_path), obj_path_(obj_path)
			, trans_inform_(trans_inform), is_3D_(is_texture_3d)
			, is_alpha_(is_texture_alpha){}
		LoaderParams(const char* vertex_path, const char* fragment_path,
			const char* texture_path, const char* obj_path,
			TextureDimensionalType is_texture_3d,
			TextureAlphaType is_texture_alpha,
			TransInform trans_inform = { glm::vec3(0.f),
			glm::vec3(0.f), glm::vec3(1.f) })
			: vertex_path_(vertex_path), fragment_path_(fragment_path)
			, texture_path_(texture_path), obj_path_(obj_path)
			, trans_inform_(trans_inform), is_3D_(is_texture_3d)
			, is_alpha_(is_texture_alpha) {}
		LoaderParams(const LoaderParams& other) = delete;
		virtual ~LoaderParams() = default;

		inline std::string get_vertex_path() const;
		inline std::string get_fragment_path() const;
		inline std::string get_texture_path() const;
		inline std::string get_obj_path() const;
		inline TransInform get_trans_inform() const;
		inline TextureDimensionalType IsTexture3D() const;
		inline TextureAlphaType IsTextureAlpha() const;
	protected:
		std::string vertex_path_;
		std::string fragment_path_;
		std::string texture_path_;
		std::string obj_path_;
		TransInform trans_inform_;
		TextureDimensionalType is_3D_;
		TextureAlphaType is_alpha_;
	};
	std::string LoaderParams::get_vertex_path() const
	{
		return vertex_path_;
	}
	std::string LoaderParams::get_fragment_path() const
	{
		return fragment_path_;
	}
	std::string LoaderParams::get_texture_path() const
	{
		return texture_path_;
	}
	std::string LoaderParams::get_obj_path() const
	{
		return obj_path_;
	}
	TransInform LoaderParams::get_trans_inform() const
	{
		return trans_inform_;
	}
	TextureDimensionalType LoaderParams::IsTexture3D() const
	{
		return is_3D_;
	}
	TextureAlphaType LoaderParams::IsTextureAlpha() const
	{
		return is_alpha_;
	}

	namespace primitive {
		class SphereParams final: public LoaderParams
		{
		public:
			SphereParams()
				: LoaderParams("resource/shaders/sphere_vs.glsl",
				"resource/shaders/sphere_fs.glsl", 
				"resource/jpg/primitive_texture.jpg", 
				"resource/obj/sphere.obj", 
				object::TextureDimensionalType::k2D,
				object::TextureAlphaType::kRGB)
			{}

			virtual ~SphereParams() = default;
		};

		class CubeParams final: public LoaderParams
		{
		public:
			CubeParams()
				: LoaderParams("resource/shaders/cube_vs.glsl",
				"resource/shaders/cube_fs.glsl",
				"resource/jpg/primitive_texture.jpg",
				"resource/obj/cube.obj",
				object::TextureDimensionalType::k2D,
				object::TextureAlphaType::kRGB)
			{}

			virtual ~CubeParams() = default;
		};

		class CapsuleParams final : public LoaderParams
		{
		public:
			CapsuleParams()
				: LoaderParams("resource/shaders/capsule_vs.glsl",
				"resource/shaders/capsule_fs.glsl",
				"resource/jpg/primitive_texture.jpg",
				"resource/obj/capsule.obj",
				object::TextureDimensionalType::k2D,
				object::TextureAlphaType::kRGB)
			{}
			
			virtual ~CapsuleParams() = default;
		};
	}	// namespace primitive
} // namespace object
#endif // GDH_ENGINE_LOADER_PARAMS_H