#include "input_manager.h"
#include "camera.h"

namespace gdh_system
{
	InputManager* InputManager::instance_ = nullptr;

	void InputManager::Update(GLFWwindow* window, float delta_time)
	{
		ProcessInputKeyboard(window, delta_time);
		ProcessInputMouse(window, delta_time);
	}

	void InputManager::ProcessInputKeyboard
		(GLFWwindow* window, float delta_time)
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, true);
		}
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		{
			object::Camera::get_instance()->Move(delta_time,
				object::CameraMovement::kForward);
		}
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		{
			object::Camera::get_instance()->Move(delta_time,
				object::CameraMovement::kBackward);
		}
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		{
			object::Camera::get_instance()->Move(delta_time,
				object::CameraMovement::kLeft);
		}
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		{
			object::Camera::get_instance()->Move(delta_time,
				object::CameraMovement::kRight);
		}
	}
	void InputManager::ProcessInputMouse(GLFWwindow* window,
		float delta_time)
	{
		glfwGetCursorPos(window,&current_mouse_x_pos_,
			&current_mouse_y_pos_);
		if (is_cursor_pos_ready_to_initialize_ == true)
		{
			last_mouse_x_pos_ = current_mouse_x_pos_;
			last_mouse_y_pos_ = current_mouse_y_pos_;
			is_cursor_pos_ready_to_initialize_ = false;
		}
		mouse_offset_x_ = current_mouse_x_pos_ - last_mouse_x_pos_;
		mouse_offset_y_ = current_mouse_y_pos_ - last_mouse_y_pos_;

		last_mouse_x_pos_ = current_mouse_x_pos_;
		last_mouse_y_pos_ = current_mouse_y_pos_;

		object::Camera::get_instance()->Rotate(delta_time,
			mouse_offset_x_, mouse_offset_y_);
	}
}	// namespace manager
