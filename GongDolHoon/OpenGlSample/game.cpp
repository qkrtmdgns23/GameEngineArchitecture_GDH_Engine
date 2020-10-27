#include "game.h"
#include "input_manager.h"

namespace system_2 {
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
		InputManager::get_instance()-> ProcessInput
			(Renderer::get_instance()-> get_opengl_window());
	}
	void Game::Update()
	{
		PlayState::get_instance()->Update();
	}
	void Game::Render() const
	{
		Renderer::get_instance()->ClearWindow();
		PlayState::get_instance()->Render();
		Renderer::get_instance()->SwapBuffer();
	}
}	// namespace system_2