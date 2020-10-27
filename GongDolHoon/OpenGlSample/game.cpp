#include "game.h"
#include "input_manager.h"

namespace system_2 {
	Game* Game::instance_ = nullptr;

	Game::Game()
	: running_(true)
	{
		Renderer::get_instance();
	}

	void Game::HandleEvents() const
	{
		InputManager::get_instance()->
			ProcessInput(Renderer::get_instance()->get_opengl_window());
	}
	void Game::Update()
	{
		
	}
	void Game::Render() const
	{
		Renderer::get_instance()->ClearWindow();
		Renderer::get_instance()->SwapBuffer();
	}
}	// namespace system_2