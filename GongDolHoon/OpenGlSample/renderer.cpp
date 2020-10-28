#include "renderer.h"
#include "error_manager.h"
#include "camera.h"
#include "game.h"

namespace system_2 {
	Renderer* Renderer::instance_ = nullptr;

	Renderer::Renderer(std::string window_title
		, unsigned int gl_major_version, unsigned int gl_minor_version
		, unsigned int window_width, unsigned int window_height)
		: window_title_(window_title), opengl_major_version_(gl_major_version)
		, opengl_minor_version_(gl_minor_version) 
		, window_width_(window_width), window_height_(window_height)
		, frame_buffer_width_(static_cast<int>(window_width))
		, frame_buffer_height_(static_cast<int>(window_height))
		,projection_matrix_(glm::mat4(0.f)), fov_(0.f), near_plane_(0.1f)
		, far_plane_(1000.f)
		, view_matrix_(glm::mat4(0.f))
	{
		if (!glfwInit())
		{
			fprintf(stderr, "Error Occured: %d", ErrorType::kGlfwInitFailed);
			glfwTerminate();
		}
		glfwWindowHint(GLFW_SAMPLES, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, gl_major_version);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, gl_minor_version);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		this->opengl_window_ = glfwCreateWindow(window_width_, window_height_
			, window_title_.c_str(), NULL, NULL);

		if (opengl_window_ == NULL)
		{
			fprintf(stderr, "Error Occured: %d", ErrorType::kWindowInitFailed);
			glfwTerminate();
		}
		glfwGetFramebufferSize(opengl_window_,
			&frame_buffer_width_, &frame_buffer_height_);
		glfwSetFramebufferSizeCallback(opengl_window_,
			Game::get_instance()->ResizeFramebuffer);
		glfwMakeContextCurrent(opengl_window_);
		glewExperimental = true;
		if (glewInit() != GLEW_OK) {
			fprintf(stderr, "Error Occured: %d", ErrorType::kGlewInitFailed);
			glfwTerminate();
		}
		glEnable(GL_DEPTH_TEST);
		glfwSetInputMode(opengl_window_, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}
	Renderer::Renderer(const char* window_title
		, unsigned int gl_major_version, unsigned int gl_minor_version
		, unsigned int window_width, unsigned int window_height)
		: opengl_major_version_(gl_major_version)
		, opengl_minor_version_(gl_minor_version)
		, window_width_(window_width), window_height_(window_height)
		, frame_buffer_width_(static_cast<int>(window_width))
		, frame_buffer_height_(static_cast<int>(window_height))
		, projection_matrix_(glm::mat4(0.f))
		, view_matrix_(glm::mat4(0.f)), fov_(0.f), near_plane_(0.1f)
		, far_plane_(1000.f)
	{
		window_title_ = window_title;
		opengl_window_ = NULL;

		if (!glfwInit())
		{
			fprintf(stderr, "Error Occured: %d", ErrorType::kGlfwInitFailed);
			glfwTerminate();
		}
		glfwWindowHint(GLFW_SAMPLES, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, gl_major_version);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, gl_minor_version);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		this->opengl_window_ = glfwCreateWindow(window_width_, window_height_
			, window_title_.c_str(), NULL, NULL);

		if (opengl_window_ == NULL)
		{
			fprintf(stderr, "Error Occured: %d", ErrorType::kWindowInitFailed);
			glfwTerminate();
		}
		glfwGetFramebufferSize(opengl_window_,
			&frame_buffer_width_, &frame_buffer_height_);
		glfwSetFramebufferSizeCallback(opengl_window_,
			Game::get_instance()->ResizeFramebuffer);
		glfwMakeContextCurrent(opengl_window_);
		glewExperimental = true;
		if (glewInit() != GLEW_OK) {
			fprintf(stderr, "Error Occured: %d", ErrorType::kGlewInitFailed);
			glfwTerminate();
		}
		glEnable(GL_DEPTH_TEST);
		glfwSetInputMode(opengl_window_, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}

	void Renderer::ConvertCoordinatesBasedOnCamera
		(object::VisibleObject* target_object)
	{
		projection_matrix_ = glm::perspective
			(glm::radians(object::Camera::get_instance()->get_zoom()),
			static_cast<float>(frame_buffer_width_) / 
			static_cast<float>(frame_buffer_height_), 
			near_plane_, far_plane_);
		view_matrix_ = object::Camera::get_instance()
			->get_view_matrix();

		target_object->SendProjectionAndViewMatrixToShader
			(projection_matrix_, view_matrix_);
	}
}	// namespace system_2