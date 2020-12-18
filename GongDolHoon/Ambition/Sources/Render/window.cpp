#include "window.h"

namespace ambition
{
	namespace render
	{
		Window::Window(const char* title, int width, int height)
			: primitive_window_(nullptr), width_(width), height_(height)
			, title_(title)
		{
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			primitive_window_ = glfwCreateWindow(width_, height_, title_.c_str(), NULL, NULL);
			if (primitive_window_ == nullptr)
			{
				std::cerr << "Primitive Window Construct Error." << std::endl;
				glfwTerminate();
			}
			glfwMakeContextCurrent(primitive_window_);
			glfwSetFramebufferSizeCallback(primitive_window_, FramebufferSizeCallback);
		}

		void Window::FramebufferSizeCallback(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}
	}	// namespace render
}		// namespace ambition