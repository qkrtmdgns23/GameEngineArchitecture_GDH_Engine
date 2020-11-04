#ifndef GDH_ENGINE_GAME_H
#define GDH_ENGINE_GAME_H

#include <iostream>
#include <string>

#include "include/GL/glew.h"		
#include "include/GLFW/glfw3.h" 
#include "renderer.h"
#include "play_state.h"

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "lib-vc2017/glew32.lib")
#pragma comment(lib, "lib-vc2017/glfw3.lib")

namespace gdh_system {
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
		Game(const Game& other) = delete;
		~Game() = default;
	private:
		Game();

		static Game* instance_;
	#pragma endregion
	public:
	#pragma region GAME_METHODS
		inline bool SystemRunning() const;
		void HandleEvents() const;
		void Update();
		void Render();
		inline void Exit();
	#pragma endregion

	// Callback Functions
	static void ResizeFramebuffer(GLFWwindow* window, int width, int height);
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
		PlayState::get_instance()->OnExit();
		glfwTerminate();
		running_ = false;
	}

}	// namespace gdh_system
#endif // GDH_ENGINE_GAME_H