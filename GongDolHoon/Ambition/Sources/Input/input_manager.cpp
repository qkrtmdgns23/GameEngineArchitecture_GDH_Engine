#include "Sources/Input/input_manager.h"

namespace ambition
{
	namespace input
	{
		InputManager::InputManager()
		{
			is_awake_ = false;
			is_update_ = false;
			is_destroy_ =false;
		}

		void InputManager::Awake()
		{
			is_awake_ = true;
		}
		
		void InputManager::Update()
		{

		}

		void InputManager::Destroy()
		{
			is_destroy_ = true;
		}

		void InputManager::ProcessInputKeyboardPressed(GLFWwindow* window)
		{
			if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			{
				glfwSetWindowShouldClose(window, true);
				std::cout << "ESC PRESSED" << std::endl;
				is_update_ = true;
			}
		}
	}	// namespace input
}		// namespace ambition