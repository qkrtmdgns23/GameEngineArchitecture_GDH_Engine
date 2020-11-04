#ifndef GDH_ENGINE_TRANSFORM_H
#define GDH_ENGINE_TRANSFORM_H

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "interface_component.h"
#include "loader_params.h"

namespace object {
	namespace component {
		class Transform : public InterfaceComponent
		{
		public:
			#pragma region CONSTRUCTOR_DESTRUCTOR
			Transform(TransInform transform_inform = 
				{ glm::vec3(0.f), glm::vec3(0.f), glm::vec3(1.f) });
			Transform(const Transform& other);
			~Transform() = default;
			#pragma endregion

			#pragma region TRANSFORM_GETTER_SETTER
			inline void set_position(const glm::vec3 position);
			inline void set_rotation(const glm::vec3 rotation);
			inline void set_scale(const glm::vec3 scale);
			inline void set_model_matrix(const glm::mat4 model);
			inline glm::mat4 get_model_matrix();
			inline bool get_is_transform_active() const;
			
			#pragma endregion

			inline void Move(const glm::vec3 position);
			inline void Rotate(const glm::vec3 rotation);
			inline void Resize(const glm::vec3 scale);
			inline virtual void SetActive() final;
			inline virtual void SetUnActive() final;
		private:
			void UpdateModelMatrix();
			#pragma region OBJECT_INFORM_VARIABLES
			glm::vec3 obj_origin_;
			glm::vec3 obj_position_;
			glm::vec3 obj_rotation_;
			glm::vec3 obj_scale_;
			#pragma endregion
			glm::mat4 model_matrix_;

			bool is_transform_active_;
		};

		void Transform::Move(const glm::vec3 position)
		{
			this->obj_position_ = position;
		}
		void Transform::Rotate(const glm::vec3 rotation)
		{
			this->obj_rotation_ = rotation;
		}
		void Transform::Resize(const glm::vec3 scale)
		{
			this->obj_scale_ = scale;
		}
		void Transform::SetActive()
		{
			is_transform_active_ = true;
		}
		void Transform::SetUnActive()
		{
			is_transform_active_ = false;
		}
		void Transform::set_position(const glm::vec3 position)
		{
			if (is_transform_active_)
			{
				this->obj_position_ = position;
			}
			else
			{
				this->obj_position_ = glm::vec3(1.0f);
			}
		}
		void Transform::set_rotation(const glm::vec3 rotation)
		{
			if (is_transform_active_)
			{
				this->obj_rotation_ = rotation;
			}
			else
			{
				this->obj_rotation_ = glm::vec3(0.f);
			}
		}
		void Transform::set_scale(const glm::vec3 scale)
		{
			if (is_transform_active_)
			{
				this->obj_scale_ = scale;
			}
			else
			{
				this->obj_scale_ = glm::vec3(0.f);
			}
		}
		void Transform::set_model_matrix(glm::mat4 model)
		{
			if (is_transform_active_)
			{
				model_matrix_ = model;
			}
			else
			{
				model_matrix_ = glm::mat4(0.f);
			}
		}
		glm::mat4 Transform::get_model_matrix()
		{
			if (is_transform_active_)
			{
				UpdateModelMatrix();
				return this->model_matrix_;
			}
			else
			{
				return glm::mat4(0.0f);
			}
		}
		bool Transform::get_is_transform_active() const
		{
			return is_transform_active_;
		}
	}	// namespace component
}	// namespace object
#endif