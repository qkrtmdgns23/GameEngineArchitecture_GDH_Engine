// library
#include "glm/gtc/matrix_transform.hpp"

// custom header
#include "visible_object.h"
#include "shader.h"
#include "mesh.h"
#include "texture.h"
#include "transform.h"

namespace gdh_engine {
	namespace object {
#pragma region Constructor & Destructor
		VisibleObject::VisibleObject(const char* vertex_path, const char* fragment_path, const char* texture_path,
			const char* obj_path, ObjTransInform target_transform,
			TextureType dimensional_inform, TextureType alpha)
		{
			object_shader_ = new Shader(vertex_path, fragment_path);
			object_texture_ = new Texture(texture_path, dimensional_inform, alpha);
			object_mesh_ = new Mesh(obj_path);
			object_transform_ = new Transform(target_transform);

			object_mesh_->SetUpMesh();
			SetTextureUniformToShader("texture1", 0);
		}
		VisibleObject::VisibleObject(std::string vertex_path, std::string fragment_path, std::string texture_path,
			const char* obj_path, ObjTransInform target_transform,
			TextureType dimensional_inform, TextureType alpha)
		{
			object_shader_ = new Shader(vertex_path, fragment_path);
			object_texture_ = new Texture(texture_path, dimensional_inform, alpha);
			object_mesh_ = new Mesh(obj_path);
			object_transform_ = new Transform(target_transform);

			object_mesh_->SetUpMesh();
			SetTextureUniformToShader("texture1", 0);
		}
		VisibleObject::VisibleObject(const char* vertex_path, const char* fragment_path, const char* texture_path,
			const char* obj_path, TextureType dimensional_inform, TextureType alpha)
		{
			object_shader_ = new Shader(vertex_path, fragment_path);
			object_texture_ = new Texture(texture_path, dimensional_inform, alpha);
			object_mesh_ = new Mesh(obj_path);
			object_transform_ = new Transform();

			object_mesh_->SetUpMesh();
			SetTextureUniformToShader("texture1", 0);
		}
		VisibleObject::VisibleObject(std::string vertex_path, const char* fragment_path, const char* texture_path,
			const char* obj_path, TextureType dimensional_inform, TextureType alpha)
		{
			object_shader_ = new Shader(vertex_path, fragment_path);
			object_texture_ = new Texture(texture_path, dimensional_inform, alpha);
			object_mesh_ = new Mesh(obj_path);
			object_transform_ = new Transform();

			object_mesh_->SetUpMesh();
			SetTextureUniformToShader("texture1", 0);
		}
	
		VisibleObject::~VisibleObject()
		{
			delete object_shader_;
			delete object_texture_;
			delete object_mesh_;
		}
#pragma endregion
		void VisibleObject::Update()
		{

		}
	
		void VisibleObject::SetupMesh()
		{
			object_mesh_->SetUpMesh();
		}
		void VisibleObject::SetTextureUniformToShader(std::string tex_uniform_name, unsigned int tex_num)
		{
			object_shader_->UseShader();
			object_shader_->SetIntegerDataTypeUniformVariable(tex_uniform_name, tex_num);
		}
		void VisibleObject::SetTextureUniformToShader(const char* tex_uniform_name, unsigned int tex_num)
		{
			object_shader_->UseShader();
			object_shader_->SetIntegerDataTypeUniformVariable(tex_uniform_name, tex_num);
		}
		void VisibleObject::ActiveTextureRendering()
		{
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, object_texture_->get_texture_id());
		}

		void VisibleObject::SetObjectTransform(ObjTransInform target_transform)
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

		void VisibleObject::SendProjectionAndViewMatrixToShader(glm::mat4 projection, glm::mat4 view)
		{
			object_shader_->SetMatrix4TypeUniformVariable("projection", projection);
			object_shader_->SetMatrix4TypeUniformVariable("view", view);
		}

		void VisibleObject::Render()
		{
			object_shader_->SetMatrix4TypeUniformVariable("model", object_transform_->get_model_matrix());

			glBindVertexArray(object_mesh_->get_vertex_array_object_identity());
			glDrawArrays(GL_TRIANGLES, 0, object_mesh_->get_num_of_vertices());
		}

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

	}	// namespace object
}	// namespace gdh_engine