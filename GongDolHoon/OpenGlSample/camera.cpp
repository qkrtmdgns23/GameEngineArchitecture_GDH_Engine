#include "include/GL/glew.h"		
#include "include/GLFW/glfw3.h" 

#include "camera.h"

namespace object {
	Camera* Camera::instance_ = nullptr;

	Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
		:front_(glm::vec3(0.f, 0.f, 0.f)), zoom_(45.f), movement_speed_(0.000005f)
		, rotate_sensitivity_(0.000002f)
	{
		this->position_ = position;
		this->up_ = up;
		this->yaw_ = yaw;
		this->pitch_ = pitch;

		UpdateCameraVectors();
	}
	Camera::Camera(float pos_x, float pos_y, float pos_z, float up_x, float up_y,
		float up_z, float yaw, float pitch) :front_(glm::vec3(0.f, 0.f, 0.f)),
		 zoom_(45.f), movement_speed_(0.000005f), rotate_sensitivity_(0.000002f)
	{
		this->position_ = glm::vec3(pos_x, pos_y, pos_z);
		this->up_ = glm::vec3(up_x, up_y, up_z);
		this->yaw_ = yaw;
		this->pitch_ = pitch;

		UpdateCameraVectors();
	}
	void Camera::Move(const float& delta_time, CameraMovement direction)
	{
		const float more_slowly = 0.001;

		switch (direction)
		{
		case CameraMovement::kForward:
			position_ += front_ * movement_speed_ * delta_time * more_slowly;
			break;
		case CameraMovement::kBackward:
			position_ -= front_ * movement_speed_ * delta_time * more_slowly;
			break;
		case CameraMovement::kRight:
			position_ += right_ * movement_speed_ * delta_time * more_slowly;
			break;
		case CameraMovement::kLeft:
			position_ -= right_ * movement_speed_ * delta_time * more_slowly;
			break;
		default:
			break;
		}
	}
	void Camera::Rotate(const float& delta_time, glm::vec2 mouse_pos)
	{
		pitch_ += static_cast<GLfloat>(mouse_pos.y) * 
			rotate_sensitivity_ * delta_time;
		yaw_ += static_cast<GLfloat>(mouse_pos.x) *
			rotate_sensitivity_ * delta_time;
		RestrictRotation();
	}
	void Camera::Rotate(const float& delta_time,
		double offset_x, double offset_y)
	{
		pitch_ += static_cast<GLfloat>(offset_y) *
			rotate_sensitivity_ * delta_time;
		yaw_ += static_cast<GLfloat>(offset_x) *
			rotate_sensitivity_ * delta_time;
		RestrictRotation();
	}
	void Camera::UpdateCameraVectors()
	{
		front_.x = cos(glm::radians(yaw_)) * cos(glm::radians(pitch_));
		front_.y = sin(glm::radians(pitch_));
		front_.z = sin(glm::radians(yaw_)) * cos(glm::radians(pitch_));
		
		front_ = glm::normalize(front_);
		right_ = glm::normalize(glm::cross(front_, world_up_));  
		up_ = glm::normalize(glm::cross(right_, front_));
	}

} // namespace object