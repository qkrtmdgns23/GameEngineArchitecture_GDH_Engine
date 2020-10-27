#include "game.h"

namespace system_2 {
	Game* Game::instance_ = nullptr;

	Game::Game()
	: running_(true)
	{
		Renderer::get_instance();
	}

	void Game::HandleEvents()
	{
		
	}
	void Game::Update()
	{
		
	}
	void Game::Render()
	{
		Renderer::get_instance()->ClearWindow();
		Renderer::get_instance()->SwapBuffer();
	}
}	// namespace system_2