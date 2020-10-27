#include "camera.h"

namespace gdh_engine {
	namespace object {
		Camera* Camera::instance_ = nullptr;

		Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
			:front_(glm::vec3(0.f, 0.f, 0.f)), movement_speed_(2.5f), zoom_(45.f)
		{
			this->position_ = position;
			this->up_ = up;
			this->yaw_ = yaw;
			this->pitch_ = pitch;

			UpdateCameraVectors();
		}
		Camera::Camera(float pos_x, float pos_y, float pos_z, float up_x, float up_y,
			float up_z, float yaw, float pitch) :front_(glm::vec3(0.f, 0.f, 0.f)),
			movement_speed_(2.5f), zoom_(45.f)
		{
			this->position_ = glm::vec3(pos_x, pos_y, pos_z);
			this->up_ = glm::vec3(up_x, up_y, up_z);
			this->yaw_ = yaw;
			this->pitch_ = pitch;

			UpdateCameraVectors();
		}

		void Camera::ProcessKeyboard(CameraMovement direction, float delta_time)
		{
			float velocity = movement_speed_ * delta_time;

			switch (direction)
			{
			case CameraMovement::kForward:
				position_ += front_ * velocity;
				break;
			case CameraMovement::kBackward:
				position_ -= front_ * velocity;
				break;
			case CameraMovement::kLeft:
				position_ -= right_ * velocity;
				break;
			case CameraMovement::kRight:
				position_ += right_ * velocity;
				break;
			default:
				break;

			}
		}

		void Camera::ProcessMouseMovement(float x_offset, float y_offset,
			bool constrain_pitch)
		{
			x_offset *= mouse_sensitivity_;
			y_offset *= mouse_sensitivity_;

			yaw_ += x_offset;
			pitch_ += y_offset;

			if (constrain_pitch)
			{
				if (pitch_ > 89.0f)
				{
					pitch_ = 89.0f;
				}
				if (pitch_ < -89.0f)
				{
					pitch_ = -89.0f;
				}
			}

			UpdateCameraVectors();
		}
		void Camera::ProcessMouseScroll(float y_offset)
		{
			zoom_ -= (float)y_offset;
			if (zoom_ < 1.0f)
			{
				zoom_ = 1.0f;
			}
			if (zoom_ > 45.0f)
			{
				zoom_ = 45.0f;
			}
		}

		void Camera::UpdateCameraVectors()
		{
			glm::vec3 front;
			front.x = cos(glm::radians(yaw_)) * cos(glm::radians(pitch_));
			front.y = sin(glm::radians(pitch_));
			front.z = sin(glm::radians(yaw_)) * cos(glm::radians(pitch_));
			front_ = glm::normalize(front);
			// also re-calculate the Right and Up vector
			right_ = glm::normalize(glm::cross(front_, world_up_));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
			up_ = glm::normalize(glm::cross(right_, front_));
		}

	} // namespace object
} // namespace gdh_engine