#ifndef GDH_ENGINE_CAMERA_H
#define GDH_ENGINE_CAMERA_H

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace object {
	enum class CameraMovement
	{
		kForward = 0,
		kBackward,
		kLeft,
		kRight,
	};

	class Camera
	{
#pragma region SINGLETON_PATTERN
	public:
		static Camera* get_instance()
		{
			if (instance_ == nullptr)
			{
				instance_ = new Camera();
			}
			return instance_;
		}
		Camera(const Camera& other) = delete;
		~Camera() = default;

	private:
		Camera(glm::vec3 position = glm::vec3(0.f),
			glm::vec3 up = glm::vec3(0.f, 0.f, -10.f),
			float yaw = -90.f, float pitch = 0.f);
		Camera(float pos_x, float pos_y, float pos_z,
			float up_x, float up_y, float up_z, float yaw,
			float pitch);
		static Camera* instance_;

#pragma endregion
	public:
#pragma region GETTER_AND_SETTER_DECLARED
		inline glm::mat4 get_view_matrix();
		inline glm::vec3 get_position() const;
		inline glm::vec3 get_front() const;
		inline glm::vec3 get_up() const;
		inline glm::vec3 get_right() const;
		inline glm::vec3 world_up() const;
		inline float get_yaw() const;
		inline float get_pitch() const;
		inline float get_zoom() const;
		inline void set_position(glm::vec3 target_position);
#pragma endregion
		void Move(const float& delta_time, CameraMovement direction);
		void Rotate(const float& delta_time, glm::vec2 mouse_pos);
		void Rotate(const float& delta_time, 
			double offset_x, double offset_y);
	private:
		void UpdateCameraVectors();
		inline void RestrictRotation();
		glm::vec3 position_;
		glm::vec3 front_;
		glm::vec3 up_;
		glm::vec3 right_;
		glm::vec3 world_up_;

		float yaw_;
		float pitch_;
		float zoom_;
		float movement_speed_;
		float rotate_sensitivity_;
	};

#pragma region GETTER_AND_SETTER_DEFINED
	glm::mat4 Camera::get_view_matrix()
	{
		UpdateCameraVectors();
		return glm::lookAt(position_, position_ + front_, up_);
	}
	glm::vec3 Camera::get_position() const
	{
		return position_;
	}
	glm::vec3 Camera::get_front() const
	{
		return front_;
	}
	glm::vec3 Camera::get_up() const
	{
		return up_;
	}
	glm::vec3 Camera::get_right() const
	{
		return right_;
	}
	glm::vec3 Camera::world_up() const
	{
		return world_up_;
	}
	float Camera::get_yaw() const
	{
		return yaw_;
	}
	float Camera::get_pitch() const
	{
		return pitch_;
	}
	float Camera::get_zoom() const
	{
		return zoom_;
	}
	void Camera::set_position(glm::vec3 target_position)
	{
		position_ = target_position;
	}
#pragma endregion
	void Camera::RestrictRotation()
	{
		if (pitch_ > 80.0f)
		{
			pitch_ = 80.0f;
		}
		else if (pitch_ < -80.0f)
		{
			pitch_ = -80.0f;
		}
		if (yaw_ > 360.0f || yaw_ < -360.0f)
		{
			yaw_ = 0.f;
		}
	}
}	// namespace object
#endif // GDH_ENGINE_CAMERA_H
