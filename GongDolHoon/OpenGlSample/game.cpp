#include "game.h"
#include "input_manager.h"
#include "time.h"

namespace gdh_system {
	Game* Game::instance_ = nullptr;

	Game::Game()
		: running_(true)
	{
		Renderer::get_instance();
		PlayState::get_instance()->OnEnter();
		object::Camera::get_instance()->
			set_position(glm::vec3(0.f, 0.f, 100.f));
	}

	void Game::HandleEvents() const
	{
		InputManager::get_instance()->Update
		(Renderer::get_instance()->get_opengl_window()
			, static_cast<float>(Time::get_instance()->get_delta_time()));
	}
	void Game::Update()
	{
		PlayState::get_instance()->Update();
	}
	void Game::Render()
	{
		Renderer::get_instance()->ClearWindow();
		PlayState::get_instance()->Render();
		Renderer::get_instance()->SwapBuffer();
	}

	void Game::ResizeFramebuffer(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
}	// namespace gdh_system