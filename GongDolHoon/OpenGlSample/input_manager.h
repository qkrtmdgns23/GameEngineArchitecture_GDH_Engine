#ifndef GDH_ENGINE_INPUT_MANAGER_H
#define GDH_ENGINE_INPUT_MANAGER_H

#include "include/GLFW/glfw3.h" 

namespace system_2 {
	// InputManager class was written as singleton pattern.
	class InputManager
	{
	public:
		void ProcessInput(GLFWwindow* window);

	#pragma region SINGLETON_PATTERN
		static InputManager* get_instance()
		{
			if (instance_ == nullptr)
			{
				instance_ = new InputManager();
			}
			return instance_;
		}
		~InputManager() {}
	private:
		InputManager() {}
		InputManager(const InputManager& other);
		
		static InputManager* instance_;
	#pragma endregion
	};
} // namespace system_2
#endif // GDH_ENGINE_INPUT_MANAGER_H

