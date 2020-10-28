#ifndef GDH_ENGINE_INPUT_MANAGER_H
#define GDH_ENGINE_INPUT_MANAGER_H

#include "include/GLFW/glfw3.h" 

namespace system_2 {
	// InputManager class was written as singleton pattern.
	class InputManager
	{
	#pragma region SINGLETON_PATTERN
	public:
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
		InputManager(): current_mouse_x_pos_(0.f), current_mouse_y_pos_(0.f)
			, last_mouse_x_pos_(0.f), last_mouse_y_pos_(0.f)
			, mouse_offset_x_(0.f), mouse_offset_y_(0.f),
			is_cursor_pos_ready_to_initialize_(true)
		{}
		// it's almost same with
		// InputManager(const InputManager& other) = delete; on public
		InputManager(const InputManager& other);
		
		static InputManager* instance_;
	#pragma endregion
	public:
		void Update(GLFWwindow* window, float delta_time);
	private:
		void ProcessInputKeyboard(GLFWwindow* window, float delta_time);
		void ProcessInputMouse(GLFWwindow* window, float delta_time);
		double current_mouse_x_pos_;
		double current_mouse_y_pos_;
		double last_mouse_x_pos_;
		double last_mouse_y_pos_;
		double mouse_offset_x_;
		double mouse_offset_y_;
		bool is_cursor_pos_ready_to_initialize_;
	};
} // namespace system_2
#endif // GDH_ENGINE_INPUT_MANAGER_H
