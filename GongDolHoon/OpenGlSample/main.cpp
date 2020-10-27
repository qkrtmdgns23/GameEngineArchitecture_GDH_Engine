#include <cstdio>

#include "game.h"
#include "error_manager.h"

using namespace system_2;

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
