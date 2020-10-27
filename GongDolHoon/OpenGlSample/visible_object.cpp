// library
#include "glm/gtc/matrix_transform.hpp"

// custom header
#include "visible_object.h"
#include "shader.h"

namespace object {
	using namespace component;
#pragma region Constructor & Destructor
	VisibleObject::VisibleObject(LoaderParams* params)
		:InterfaceObject(params)
	{
		object_shader_ = 
			new Shader(params->get_vertex_path(), params->get_fragment_path());
		object_texture_ = 
			new Texture(params->get_texture_path()
			, params->IsTexture3D() 
			, params->IsTextureAlpha());
		object_mesh_ = new Mesh(params->get_obj_path());
		object_transform_ = 
			new Transform(params->get_trans_inform());

		object_mesh_->SetUpMesh();
		SetTextureUniformToShader("texture1", 0);
	}
	VisibleObject::~VisibleObject()
	{
		delete object_shader_;
		delete object_texture_;
		delete object_mesh_;
		delete object_transform_;
	}
#pragma endregion
	void VisibleObject::Update()
	{
		SetObjectRotation(
			glm::vec3(glfwGetTime() * 10.f, 0.f, 0.f));
	}
	void VisibleObject::Clean()
	{

	}
	void VisibleObject::Render() const
	{
		ActiveTextureRendering();
		object_shader_->SetMatrix4TypeUniformVariable
			("model", object_transform_->get_model_matrix());
		glBindVertexArray
			(object_mesh_->get_vertex_array_object_identity());
		glDrawArrays
			(GL_TRIANGLES, 0, object_mesh_->get_num_of_vertices());
	}
	void VisibleObject::SendProjectionAndViewMatrixToShader
	(glm::mat4 projection, glm::mat4 view)
	{
		object_shader_->
			SetMatrix4TypeUniformVariable("projection", projection);
		object_shader_->
			SetMatrix4TypeUniformVariable("view", view);
	}
	void VisibleObject::SetTextureUniformToShader
	(std::string tex_uniform_name, unsigned int tex_num) const
	{
		object_shader_->UseShader();
		object_shader_->
			SetIntegerDataTypeUniformVariable
			(tex_uniform_name, tex_num);
	}
	void VisibleObject::SetTextureUniformToShader
	(const char* tex_uniform_name, unsigned int tex_num) const
	{
		object_shader_->UseShader();
		object_shader_->
			SetIntegerDataTypeUniformVariable
			(tex_uniform_name, tex_num);
	}
}	// namespace 