#ifndef GDH_ENGINE_RENDERER_H
#define GDH_ENGINE_RENDERER_H

#include "include/GL/glew.h"	
#include "include/GLFW/glfw3.h" 
#include "visible_object.h"

#include <string>
namespace gdh_system {
	class Renderer {
	#pragma region SINGLETON_PATTERN
	public:
		static Renderer* get_instance()
		{
			if (instance_ == nullptr)
			{
				instance_ = new Renderer("GDH_ENGINE_VER2"
					, 3, 3, 1024, 768);
			}
			return instance_;
		}

		Renderer(const Renderer& other) = delete;
		~Renderer() = default;

	private:
		Renderer(std::string window_title
			, unsigned int gl_major_version, unsigned int gl_minor_version
			, unsigned int window_width, unsigned int window_height);
		Renderer(const char* window_title
			,unsigned int gl_major_version, unsigned int gl_minor_version
			,unsigned int window_width, unsigned int window_height);

		static Renderer* instance_;
	#pragma endregion
	public:
		inline void ClearWindow() const;
		inline void SwapBuffer() const;
		inline bool IsWindowClosed() const;

		inline GLFWwindow* get_opengl_window() const;
		void ConvertCoordinatesBasedOnCamera
			(object::VisibleObject* target_object);

	private:
	#pragma region WINDOW_DATA
		unsigned int window_width_;
		unsigned int window_height_;
		int frame_buffer_width_;
		int frame_buffer_height_;
		unsigned int opengl_major_version_;
		unsigned int opengl_minor_version_;
		std::string window_title_;
		GLFWwindow* opengl_window_;
	#pragma endregion
		glm::mat4	projection_matrix_;
		float fov_;
		float near_plane_;
		float far_plane_;

		glm::mat4	view_matrix_;
	};
	void Renderer::ClearWindow() const
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	void Renderer::SwapBuffer() const
	{
		glfwSwapBuffers(opengl_window_);
		glfwPollEvents();
	}

	bool Renderer::IsWindowClosed() const
	{
		if (glfwWindowShouldClose(this->opengl_window_))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	GLFWwindow* Renderer::get_opengl_window() const
	{
		return opengl_window_;
	}
} // namespace gdh_system

#endif // GDH_ENGINE_RENDERER_H