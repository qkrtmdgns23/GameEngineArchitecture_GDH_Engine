#ifndef GDH_ENGINE_VISIBLE_OBJECT_H
#define GDH_ENGINE_VISIBLE_OBJECT_H

#include <string>
#include <vector>
#include "glm/glm.hpp"

#include "interface_object.h"
#include "gdh_behaviour.h"
#include "loader_params.h"

#pragma region COMPONENT_HEADER
#include "transform.h"
#include "mesh.h"
#include "texture.h"
#pragma endregion

namespace object {
	using namespace component;
	class Shader;

	class VisibleObject : public InterfaceObject, 
		public gdh_system::GongDolHoonBehaviour
	{
	public:
#pragma region CONSTRUCTOR_DESTRUCTOR
		VisibleObject(LoaderParams* params);
		VisibleObject(const VisibleObject& other) = delete;
		virtual ~VisibleObject();
#pragma endregion
		// Overriding
		virtual void Start() override;
		virtual void FixedUpdate() override;
		virtual void Update() override;
		virtual void RenderObject() override;
		virtual void Destroy() override;

		inline void SetupMesh();
#pragma region RELATE_WITH_SHADERS
		void SetTextureUniformToShader
		(std::string tex_uniform_name, unsigned int tex_num) const;
		void SetTextureUniformToShader
		(const char* tex_uniform_name, unsigned int tex_num) const;
		void SendProjectionAndViewMatrixToShader
		(glm::mat4 projection, glm::mat4 view);
#pragma endregion
#pragma region TRANSFORM_COMPONENT_METHODS
		inline void SetObjectTransform(TransInform target_transform);
		inline void SetObjectPosition(glm::vec3 target_position);
		inline void SetObjectRotation(glm::vec3 target_rotation);
		inline void SetObjectScale(glm::vec3 target_scale);
		inline void MoveObject(glm::vec3 position);
		inline void RotateObject(glm::vec3 rotation);
		inline void ResizeObject(glm::vec3 scale);
#pragma endregion
#pragma region COMPONENT_ACTIVE_METHODS_DECLARED
		inline void SetTextureActive();
		inline void SetTransformActive();
		inline void SetMeshActive();
		inline void SetTextureUnActive();
		inline void SetTransformUnActive();
		inline void SetMeshUnActive();
#pragma endregion
	private:
		inline void ActiveTextureRendering() const;
		Texture* object_texture_;
		Shader* object_shader_;
		Mesh* object_mesh_;
		Transform* object_transform_;

		glm::mat4 object_view_matrix_;
		glm::mat4 object_projection_matrix_;
	};
	void VisibleObject::SetupMesh()
	{
		object_mesh_->SetUpMesh();
	}
#pragma region TRANSFORM_COMPONENT_METHODS
	void VisibleObject::SetObjectTransform(TransInform target_transform)
	{
		object_transform_->set_position(target_transform.position);
		object_transform_->set_rotation(target_transform.rotation);
		object_transform_->set_scale(target_transform.scale);
	}
	void VisibleObject::SetObjectPosition(glm::vec3 target_position)
	{
		object_transform_->set_position(target_position);
	}
	void VisibleObject::SetObjectRotation(glm::vec3 target_rotation)
	{
		object_transform_->set_rotation(target_rotation);
	}
	void VisibleObject::SetObjectScale(glm::vec3 target_scale)
	{
		object_transform_->set_scale(target_scale);
	}
	void VisibleObject::MoveObject(glm::vec3 position)
	{
		object_transform_->Move(position);
	}
	void VisibleObject::RotateObject(glm::vec3 rotation)
	{
		object_transform_->Rotate(rotation);
	}
	void VisibleObject::ResizeObject(glm::vec3 scale)
	{
		object_transform_->Resize(scale);
	}
#pragma endregion
	void VisibleObject::ActiveTextureRendering() const
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, object_texture_->get_texture_id());
	}
#pragma region COMPONENT_ACTIVE_METHODS_DEFINED
	void VisibleObject::SetTextureActive()
	{
		object_texture_->SetActive();
	}
	void VisibleObject::SetTransformActive()
	{
		object_transform_->SetActive();
	}
	void VisibleObject::SetMeshActive()
	{
		object_mesh_->SetActive();
	}
	void VisibleObject::SetTextureUnActive()
	{
		object_texture_->SetUnActive();
	}
	void VisibleObject::SetTransformUnActive()
	{
		object_transform_->SetUnActive();
	}
	void VisibleObject::SetMeshUnActive()
	{
		object_mesh_->SetUnActive();
	}
#pragma endregion
}	// namespace object

#endif // GDH_ENGINE_VISIBLE_OBJECT_H