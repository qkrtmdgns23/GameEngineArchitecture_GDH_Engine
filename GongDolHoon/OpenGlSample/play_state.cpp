#include "play_state.h"
#include "input_manager.h"
#include "renderer.h"
#include "interface_object.h"
#include "visible_object.h"
#include <cstdio>

namespace system_2 {
	const std::string PlayState::state_id_ = "PLAY";
	PlayState* PlayState::instance_ = NULL;

	void PlayState::Update()
	{
		for (size_t i = 0; i < game_objects_.size(); ++i)
		{
			game_objects_[i]->Update();
		}
	}
	void PlayState::Render()
	{
		for (size_t i = 0; i < game_objects_.size(); ++i)
		{
			game_objects_[i]->Render();
		} 
	}
	bool PlayState::OnEnter()
	{
		fprintf(stdout, "Enter On PlayState\n");
		object::InterfaceObject* sphere 
			= new object::VisibleObject(new
				object::primitive::SphereParams);
		assert(sphere != NULL);
		game_objects_.push_back(sphere);

		return true;
	}
	bool PlayState::OnExit()
	{
		fprintf(stdout, "Exit On ExitState\n");
		for (size_t i = 0; i < game_objects_.size(); ++i)
		{
			game_objects_[i]->Clean();
		}
		game_objects_.clear();
		return true;
	}
	
}	// namespace system_2