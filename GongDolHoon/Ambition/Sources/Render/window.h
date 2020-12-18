#ifndef __AMBITION_WINDOW__
#define __AMBITION_WINDOW__

#include "framework.h"
#include "pch.h"

namespace ambition
{
	namespace render
	{
		AMBITION_CLASS Window
		{
		public:
								Window(const char* title, int width, int height);
								~Window()											= default;

			inline GLFWwindow*	GetWindow() const
			{
				return primitive_window_;
			}

		private:
			GLFWwindow*			primitive_window_;
			std::string			title_;
			
			int16_t				width_;
			int16_t				height_;
			
		};
	}	// namespace render
}		// namespace ambition

#endif	// __AMBITION_WINDOW__