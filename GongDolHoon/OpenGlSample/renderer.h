#ifndef GDH_ENGINE_RENDERER_H
#define GDH_ENGINE_RENDERER_H

#include "include/GLFW/glfw3.h" 

// custom header
#include "visible_object.h"
#include "camera.h"

namespace gdh_engine {
	namespace manager {
		class Renderer {
		public:
			void ClearWindowToRender();
			void SwapBuffearsOnWindow();
			bool IsWindowShouldClose();

			void ShutDown();

			GLFWwindow* get_engine_window() const
			{
				return engine_window_;
			}

			static Renderer* get_instance()
			{
				if (instance_ == nullptr)
				{
					instance_ = 
						new Renderer("GDH_ENGINE(VER1.0.4)", 3, 3);
				}

				return instance_;
			}

			void ConvertCoordinatesForRender(object::Camera* camera, object::VisibleObject* target_object);
			void Render(object::VisibleObject* target_obj);

			// it's callback function in openGL
			static void ResizeWindowFrameBuffer(GLFWwindow* window, int fbw, int fbh);

			const unsigned int kGlfwContextMajorVersion;
			const unsigned int kGlfwContextMinorVersion;

		private:
			// this constructor don't need string overloaded function becuase of singleton.
			Renderer(const char* title, const unsigned int kMajorVersion, 
				const unsigned int kMinorVersion,
				const unsigned int kWindowHeight = 724, const unsigned int kWindowWidth = 1028);
			~Renderer() {}

			static Renderer* instance_;

			size_t window_width_;
			size_t window_height_;

			glm::mat4 projection_matrix_;
			glm::mat4 view_matrix_;

			std::string engine_window_title_;

			GLFWwindow* engine_window_;
		};
	} // namespace manager
} // namespace gdh_engine

#endif // GDH_ENGINE_RENDERER_H