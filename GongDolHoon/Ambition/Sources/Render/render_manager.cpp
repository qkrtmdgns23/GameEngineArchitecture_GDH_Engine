#include "render_manager.h"
#include "window.h"

namespace ambition
{
	namespace render
	{
		RenderManager::RenderManager()
			:window_(nullptr), inform_()
		{
			is_awake_ = false;
			is_update_ = false;
			is_destroy_ = false;
		}

		void RenderManager::Awake()
		{
			if (!glfwInit())
			{
				std::cerr << "GLFW Init Failed.";
			}

			window_ = new Window(inform_.title, inform_.width, inform_.height);
			
			is_awake_ = true;
		}

		void RenderManager::Update()
		{
			/* Render here */
			glClear(GL_COLOR_BUFFER_BIT);

			/* Swap front and back buffers */
			glfwSwapBuffers(window_->GetWindow());

			/* Poll for and process events */
			glfwPollEvents();

			if (glfwWindowShouldClose(window_->GetWindow()))
			{
				is_update_ = true;
			}
		}

		void RenderManager::Destroy()
		{
			glfwTerminate();
			is_destroy_ = true;
		}
	}		// namespace render
}			// namespace ambition