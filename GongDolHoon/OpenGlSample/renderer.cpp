#include <iostream>

// library
#include "include/GL/glew.h"	
#include "glm/gtc/matrix_transform.hpp"

// custom header
#include "renderer.h"

namespace gdh_engine {
	namespace manager {
		Renderer* Renderer::instance_ = nullptr;
		
		Renderer::Renderer(const char* title, const unsigned int kMajorVersion, const unsigned int kMinorVersion,
			const unsigned int kWindowHeight, const unsigned int kWindowWidth)
			: kGlfwContextMajorVersion(kMajorVersion), kGlfwContextMinorVersion(kMinorVersion)
		{
			this->engine_window_title_ = title;
			this->window_height_ = kWindowHeight;
			this->window_width_ = kWindowWidth;
			this->engine_window_ = nullptr;

			glfwInit();
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, kGlfwContextMajorVersion);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, kGlfwContextMinorVersion);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			this->engine_window_ = glfwCreateWindow(window_width_, window_height_, engine_window_title_.c_str(), NULL, NULL);
			if (engine_window_ == NULL)
			{
				fprintf(stderr, "Failed to Create Glfw Window.\n");
				glfwTerminate();
			}

			glfwMakeContextCurrent(engine_window_);
			glfwSetFramebufferSizeCallback(engine_window_, ResizeWindowFrameBuffer);

			glewExperimental = true; // Needed for core profile

			if (glewInit() != GLEW_OK) {
				fprintf(stderr, "Failed to initialize GLEW\n");
				glfwTerminate();
			}

			glEnable(GL_DEPTH_TEST);
		}

		void Renderer::ShutDown()
		{
			glfwTerminate();
		}

		void Renderer::ClearWindowToRender()
		{
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Renderer::SwapBuffearsOnWindow()
		{
			glfwSwapBuffers(engine_window_);
			glfwPollEvents();
		}

		bool Renderer::IsWindowShouldClose()
		{
			if (glfwWindowShouldClose(this->engine_window_))
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		void Renderer::ConvertCoordinatesForRender(object::Camera* camera, object::VisibleObject* target_object)
		{
			projection_matrix_ = glm::perspective(glm::radians(camera->get_zoom()), 
				(float)1024 / 728, 0.1f, 100.0f);
			view_matrix_ = camera->get_view_matrix();

			target_object->SendProjectionAndViewMatrixToShader(projection_matrix_, view_matrix_);
		}

		void Renderer::Render(object::VisibleObject* target_obj)
		{
			ClearWindowToRender();
			target_obj->ActiveTextureRendering();
			target_obj->Render();
			SwapBuffearsOnWindow();
		}

		void Renderer::ResizeWindowFrameBuffer(GLFWwindow* window, int fbw, int fbh)
		{
			glViewport(0, 0, fbw, fbh);
		}
	} // namespace manager
} // namespace gdh_engine