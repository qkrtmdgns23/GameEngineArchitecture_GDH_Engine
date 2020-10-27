#include "input_manager.h"

namespace system_2
{
	InputManager* InputManager::instance_ = nullptr;

	void InputManager::ProcessInput(GLFWwindow* window)
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, true);
		}
	}
}	// namespace manager
