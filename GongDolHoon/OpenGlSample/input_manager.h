#ifndef GDH_ENGINE_INPUT_MANAGER_H
#define GDH_ENGINE_INPUT_MANAGER_H

#include "include/GLFW/glfw3.h" 

namespace gdh_engine {
	namespace manager {
		// InputManager class was written as singleton pattern.
		class InputManager
		{
		public:
			void ProcessInput(GLFWwindow* window);

			static InputManager* get_instance()
			{
				if (instance_ == nullptr)
				{
					instance_ = new InputManager();
				}
				return instance_;
			}
		private:
			InputManager() {}
			InputManager(const InputManager& other);
			~InputManager() {}

			static InputManager* instance_;
		};
	} // namespace manager
} // namespace gdh_engine

#endif // GDH_ENGINE_INPUT_MANAGER_H

