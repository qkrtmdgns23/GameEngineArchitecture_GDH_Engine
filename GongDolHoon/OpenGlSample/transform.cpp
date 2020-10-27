#include "Transform.h"
#include "visible_object.h"

namespace gdh_engine {
	namespace object {
		Transform::Transform(ObjTransInform transform_inform)
			: is_transform_active_(true)
			, obj_origin_(glm::vec3(0.0))
			, obj_position_(transform_inform.position) 
			, obj_rotation_(transform_inform.rotation)
			, obj_scale_(transform_inform.scale)
			, model_matrix_(glm::mat4(1.0))
		{

		}
		void Transform::Move(const glm::vec3 position)
		{
			this->obj_position_ += position;
		}

		void Transform::Rotate(const glm::vec3 rotation)
		{
			this->obj_rotation_ += rotation;
		}

		void Transform::Resize(const glm::vec3 scale)
		{
			this->obj_scale_ += scale;
		}

		void Transform::UpdateModelMatrix()
		{
			this->model_matrix_ = glm::mat4(1.f);
			this->model_matrix_ = glm::translate(this->model_matrix_, this->obj_origin_);
			this->model_matrix_ = glm::rotate(this->model_matrix_, glm::radians(this->obj_rotation_.x), glm::vec3(1.f, 0.f, 0.f));
			this->model_matrix_ = glm::rotate(this->model_matrix_, glm::radians(this->obj_rotation_.y), glm::vec3(0.f, 1.f, 1.f));
			this->model_matrix_ = glm::rotate(this->model_matrix_, glm::radians(this->obj_rotation_.z), glm::vec3(0.f, 0.f, 1.f));
			this->model_matrix_ = glm::translate(this->model_matrix_, this->obj_position_ - this->obj_origin_);
			this->model_matrix_ = glm::scale(this->model_matrix_, this->obj_scale_);
		}

		void Transform::SetActive()
		{
			is_transform_active_ = true;
		}

		void Transform::SetUnActive()
		{
			is_transform_active_ = false;
		}
	}	// namespace object
}	// namespace gdh_engine