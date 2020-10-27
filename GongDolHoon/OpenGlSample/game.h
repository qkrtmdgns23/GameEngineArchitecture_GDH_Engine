#ifndef GDH_ENGINE_GAME_H
#define GDH_ENGINE_GAME_H

#include <iostream>
#include <string>
#include "include/GLFW/glfw3.h" 
#include "renderer.h"

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "lib-vc2017/glew32.lib")
#pragma comment(lib, "lib-vc2017/glfw3.lib")

namespace system_2 {
	class Game
	{
	#pragma region SINGLETON_PATTERN
	public:
		static Game* get_instance()
		{
			if (instance_ == nullptr)
			{
				instance_ = new Game();
				return instance_;
			}

			return instance_;
		}
		~Game() {}
	private:
		Game();

		static Game* instance_;
	#pragma endregion
	public:
	#pragma region GAME_METHODS
		inline bool SystemRunning() const;
		void HandleEvents();
		void Update();
		void Render();
		inline void Exit();
	#pragma endregion
	private: 
		bool running_;
	};

	bool Game::SystemRunning() const
	{
		if (Renderer::get_instance()->IsWindowClosed() == false)
		{
			return running_;
		}
		return false;	
	}

	void Game::Exit()
	{
		glfwTerminate();
		running_ = false;
	}

}	// namespace system_2
#endif // GDH_ENGINE_GAME_H