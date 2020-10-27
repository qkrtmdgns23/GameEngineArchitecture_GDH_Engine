#ifndef GDH_ENGINE_TRANSFORM_H
#define GDH_ENGINE_TRANSFORM_H

// library
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

// custom header
#include "interface_component.h"

namespace gdh_engine {
	namespace object {
		typedef struct ObjectTransformInformation
		{
			glm::vec3 position;
			glm::vec3 rotation;
			glm::vec3 scale;
		}ObjTransInform;

		class Object;

		class Transform : public InterfaceComponent
		{
		public:
			Transform(ObjTransInform transform_inform = { glm::vec3(0.f), glm::vec3(0.f), glm::vec3(1.f) });

			// method
			void Move(const glm::vec3 position);
			void Rotate(const glm::vec3 rotation);
			void Resize(const glm::vec3 scale);

			virtual void SetActive() final;
			virtual void SetUnActive() final;


			void set_position(const glm::vec3 position)
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
			void set_rotation(const glm::vec3 rotation)
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
			void set_scale(const glm::vec3 scale)
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
			void set_model_matrix(glm::mat4 model)
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
			glm::mat4 get_model_matrix()
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
			bool get_is_transform_active()
			{
				return is_transform_active_;
			}

		private:
			// this function called in move, rotate, resize, setter
			void UpdateModelMatrix();
			bool is_transform_active_;

			glm::vec3 obj_origin_;
			glm::vec3 obj_position_;
			glm::vec3 obj_rotation_;
			glm::vec3 obj_scale_;

			glm::mat4 model_matrix_;
		};
	} // namespace object
} // namespace gdh_engine

#endif // GDH_ENGINE_TRANSFORM_H
