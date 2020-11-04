#include "Transform.h"

namespace object {
	namespace component {
		Transform::Transform(TransInform transform_inform)
			: is_transform_active_(true)
			, obj_origin_(glm::vec3(0.0))
			, obj_position_(transform_inform.position)
			, obj_rotation_(transform_inform.rotation)
			, obj_scale_(transform_inform.scale)
			, model_matrix_(glm::mat4(1.0))
		{ }
		Transform::Transform(const Transform& other)
			: is_transform_active_(other.is_transform_active_)
			, obj_origin_(other.obj_origin_)
			, obj_position_(other.obj_position_)
			, obj_rotation_(other.obj_rotation_)
			, obj_scale_(other.obj_scale_)
			, model_matrix_(other.model_matrix_)
		{ }

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
	}	// namespace component
} // namespace object