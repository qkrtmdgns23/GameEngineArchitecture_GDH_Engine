#include "window.h"

namespace ambition
{
	namespace render
	{
		Window::Window(const char* title, int width, int height)
			: primitive_window_(nullptr), width_(width), height_(height)
			, title_(title)
		{
			primitive_window_ = glfwCreateWindow(width_, height_, title_.c_str(), NULL, NULL);
			if (primitive_window_ == nullptr)
			{
				std::cerr << "Primitive Window Construct Error." << std::endl;
				glfwTerminate();
			}
			glfwMakeContextCurrent(primitive_window_);
		}
	}	// namespace render
}		// namespace ambition