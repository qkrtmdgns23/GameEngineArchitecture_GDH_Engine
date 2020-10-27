#include "input_manager.h"

namespace gdh_engine {
	namespace manager {
		InputManager* InputManager::instance_ = nullptr;

		void InputManager::ProcessInput(GLFWwindow* window)
		{
			if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			{
				glfwSetWindowShouldClose(window, true);
			}
		}
	}	// namespace manager
}	// namespace gdh_engine