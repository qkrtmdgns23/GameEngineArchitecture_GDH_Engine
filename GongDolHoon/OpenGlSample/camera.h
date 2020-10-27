#ifndef GDH_ENGINE_CAMERA_H
#define GDH_ENGINE_CAMERA_H

// library
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

		~Camera() {}

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
		inline glm::mat4 get_view_matrix() const;
		inline glm::vec3 get_position() const;
		inline glm::vec3 get_front() const;
		inline glm::vec3 get_up() const;
		inline glm::vec3 get_right() const;
		inline glm::vec3 world_up() const;
		inline float get_yaw() const;
		inline float get_pitch() const;
		inline float get_zoom() const;
		inline void set_position(glm::vec3 target_position);
	private:
		void UpdateCameraVectors();

		glm::vec3 position_;
		glm::vec3 front_;
		glm::vec3 up_;
		glm::vec3 right_;
		glm::vec3 world_up_;

		float yaw_;
		float pitch_;
		float zoom_;
	};

	glm::mat4 Camera::get_view_matrix() const
	{
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
}	// namespace object
#endif // GDH_ENGINE_CAMERA_H
