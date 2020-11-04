#ifndef GDH_ENGINE_PLAY_STATE_H
#define GDH_ENGINE_PLAY_STATE_H

#include "include/GL/glew.h"		
#include "include/GLFW/glfw3.h" 

#include "camera.h"
#include "interface_game_state.h"

namespace gdh_system {
	class PlayState : public InterfaceGameState
	{
	public:
	#pragma region OVERRIDING_FUNC
		virtual void Update() override;
		virtual void Render() override;
		virtual bool OnEnter() override;
		virtual bool OnExit() override;
		inline virtual std::string get_state_identity() const;
	#pragma endregion
	private:
		static const std::string state_id_;
	#pragma region SINGLETON_PATTERN
	public:
		PlayState(const PlayState& other) = delete;
		~PlayState() = default;
		static PlayState* get_instance()
		{
			if (instance_ == nullptr)
			{
				instance_ = new PlayState();
			}
			return instance_;
		}
	private:
		PlayState() {
			play_state_camera_ = object::Camera::get_instance();
		}
		static PlayState* instance_;
		object::Camera* play_state_camera_;
	#pragma endregion
	};

	std::string PlayState::get_state_identity() const
	{
		return state_id_;
	}
}	// namespace gdh_system
#endif // GDH_ENGINE_PLAY_STATE_H