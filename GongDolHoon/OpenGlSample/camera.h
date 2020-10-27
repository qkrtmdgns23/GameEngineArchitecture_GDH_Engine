#ifndef GDH_ENGINE_CAMERA_H
#define GDH_ENGINE_CAMERA_H

// library
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace gdh_engine {
	namespace object {
		enum class CameraMovement;

		class Camera
		{
		public:
			void ProcessKeyboard(CameraMovement direction, float delta_time);
			void ProcessMouseMovement(float x_offset, float y_offset,
				bool constrain_pitch = true);
			void ProcessMouseScroll(float y_offset);

			static Camera* get_instance()
			{
				if (instance_ == nullptr)
				{
					instance_ = new Camera();
				}

				return instance_;
			}

			glm::mat4 get_view_matrix()
			{
				return glm::lookAt(position_, position_ + front_, up_);
			}
			glm::vec3 get_position() const
			{
				return position_;
			}
			glm::vec3 get_front() const
			{
				return front_;
			}
			glm::vec3 get_up() const
			{
				return up_;
			}
			glm::vec3 get_right() const
			{
				return right_;
			}
			glm::vec3 world_up() const
			{
				return world_up_;
			}
			float get_yaw() const
			{
				return yaw_;
			}
			float get_pitch() const
			{
				return pitch_;
			}
			float get_movement_speed() const
			{
				return movement_speed_;
			}
			float get_movement_sensitivity() const
			{
				return mouse_sensitivity_;
			}
			float get_zoom() const
			{
				return zoom_;
			}

			void set_camera_position(glm::vec3 target_position)
			{
				position_ = target_position;
			}
		private:
			Camera(glm::vec3 position = glm::vec3(0.f, 0.f, 0.f),
				glm::vec3 up = glm::vec3(0.f, 0.f, -10.f), float yaw = -90.f, float pitch = 0.f);
			Camera(float pos_x, float pos_y, float pos_z,
				float up_x, float up_y, float up_z, float yaw, float pitch);
			~Camera() {}

			static Camera* instance_;

			void UpdateCameraVectors();

			glm::vec3 position_;
			glm::vec3 front_;
			glm::vec3 up_;
			glm::vec3 right_;
			glm::vec3 world_up_;

			float yaw_;
			float pitch_;
			float movement_speed_;
			float mouse_sensitivity_;
			float zoom_;
		};

		enum class CameraMovement
		{
			kForward = 0,
			kBackward,
			kLeft,
			kRight,
		};
	}	// namespace object
}	// namespace gdh_engine
#endif // GDH_ENGINE_CAMERA_H
