#ifndef GDH_ENGINE_VISIBLE_OBJECT_H
#define GDH_ENGINE_VISIBLE_OBJECT_H

#include <string>
#include <vector>

// library
#include "glm/glm.hpp"

// custom library
#include "interface_object.h"

namespace gdh_engine {
	namespace object {
		class Texture;
		class Shader;
		class Mesh;
		class Transform;
		enum class TextureType;

		typedef struct ObjectTransformInformation ObjTransInform;

		class VisibleObject : public InterfaceObject
		{
		public:
			// Constructer & Destructor
			VisibleObject(const char* vertex_path, const char* fragment_path, const char* texture_path, 
				const char* obj_path, ObjTransInform target_transform, 
				TextureType dimensional_inform, TextureType alpha);
			VisibleObject(std::string vertex_path, std::string fragment_path, std::string texture_path,
				const char* obj_path, ObjTransInform target_transform,
				TextureType dimensional_inform, TextureType alpha);
			VisibleObject(const char* vertex_path, const char* fragment_path, const char* texture_path,
				const char* obj_path, TextureType dimensional_inform, TextureType alpha);
			VisibleObject(std::string vertex_path, const char* fragment_path, const char* texture_path,
				const char* obj_path, TextureType dimensional_inform, TextureType alpha);
			virtual ~VisibleObject();

			// Overriding
			virtual void Update() override;

			void SetupMesh();
			void SetTextureUniformToShader(std::string tex_uniform_name, unsigned int tex_num);
			void SetTextureUniformToShader(const char* tex_uniform_name, unsigned int tex_num);
			void ActiveTextureRendering();
			void Render();
			void SendProjectionAndViewMatrixToShader(glm::mat4 projection, glm::mat4 view);

			// About Transform
			void SetObjectTransform(ObjTransInform target_transform);
			void SetObjectPosition(glm::vec3 target_position);
			void SetObjectRotation(glm::vec3 target_rotation);
			void SetObjectScale(glm::vec3 target_scale);
			void MoveObject(glm::vec3 position);
			void RotateObject(glm::vec3 rotation);
			void ResizeObject(glm::vec3 scale);

			// About Component Active
			void SetTextureActive();
			void SetTransformActive();
			void SetMeshActive();
			void SetTextureUnActive();
			void SetTransformUnActive();
			void SetMeshUnActive();

		private:
			Texture* object_texture_;
			Shader* object_shader_;
			Mesh* object_mesh_;
			Transform* object_transform_;

			glm::mat4 object_view_matrix_;
			glm::mat4 object_projection_matrix_;
		};
	}	// namespace object
}	// namespace gdh_engine

#endif // GDH_ENGINE_VISIBLE_OBJECT_H