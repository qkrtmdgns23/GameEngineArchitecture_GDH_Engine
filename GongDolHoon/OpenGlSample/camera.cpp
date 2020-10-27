#include "camera.h"

namespace object {
	Camera* Camera::instance_ = nullptr;

	Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
		:front_(glm::vec3(0.f, 0.f, 0.f)), zoom_(45.f)
	{
		this->position_ = position;
		this->up_ = up;
		this->yaw_ = yaw;
		this->pitch_ = pitch;

		UpdateCameraVectors();
	}
	Camera::Camera(float pos_x, float pos_y, float pos_z, float up_x, float up_y,
		float up_z, float yaw, float pitch) :front_(glm::vec3(0.f, 0.f, 0.f)),
		 zoom_(45.f)
	{
		this->position_ = glm::vec3(pos_x, pos_y, pos_z);
		this->up_ = glm::vec3(up_x, up_y, up_z);
		this->yaw_ = yaw;
		this->pitch_ = pitch;

		UpdateCameraVectors();
	}

	void Camera::UpdateCameraVectors()
	{
		glm::vec3 front;
		front.x = cos(glm::radians(yaw_)) * cos(glm::radians(pitch_));
		front.y = sin(glm::radians(pitch_));
		front.z = sin(glm::radians(yaw_)) * cos(glm::radians(pitch_));
		front_ = glm::normalize(front);
		right_ = glm::normalize(glm::cross(front_, world_up_));  
		up_ = glm::normalize(glm::cross(right_, front_));
	}

} // namespace object