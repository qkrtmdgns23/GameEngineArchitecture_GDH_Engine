#include <cstdio>

#include "game.h"

using namespace gdh_system;

int main(void)
{
	Game::get_instance();
	while (Game::get_instance()->SystemRunning())
	{
		Game::get_instance()->HandleEvents();
		Game::get_instance()->Update();
		Game::get_instance()->Render();
	}
	Game::get_instance()->Exit();

	return 0;
}
