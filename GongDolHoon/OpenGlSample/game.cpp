#include "game.h"
#include "input_manager.h"

namespace system_2 {
	Game* Game::instance_ = nullptr;

	Game::Game()
	: running_(true), delta_time_(0.f),
	current_frame_(0.f), last_frame_(0.f)
	{
		Renderer::get_instance();
		PlayState::get_instance()->OnEnter();
		object::Camera::get_instance()->
			set_position(glm::vec3(0.f, 0.f, 100.f));
	}

	void Game::HandleEvents() const
	{
		InputManager::get_instance()-> Update
			(Renderer::get_instance()-> get_opengl_window(), delta_time_);
	}
	void Game::Update()
	{	
		#pragma region GET_TIME_PER_FRAMES
		current_frame_ = glfwGetTime();
		delta_time_ = current_frame_ - last_frame_;
		last_frame_ = current_frame_;
		#pragma endregion
		PlayState::get_instance()->Update();
	}
	void Game::Render() const
	{
		Renderer::get_instance()->ClearWindow();
		PlayState::get_instance()->Render();
		Renderer::get_instance()->SwapBuffer();
	}

	void Game::ResizeFramebuffer(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
}	// namespace system_2