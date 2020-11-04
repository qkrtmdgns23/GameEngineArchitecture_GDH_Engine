#include "play_state.h"
#include "renderer.h"
#include "interface_object.h"
#include "visible_object.h"
#include <cstdio>

namespace gdh_system {
	const std::string PlayState::state_id_ = "PLAY";
	PlayState* PlayState::instance_ = NULL;

	void PlayState::Update()
	{
		assert(game_objects_[0] != NULL);
		for (size_t i = 0; i < game_objects_.size(); ++i)
		{
			game_objects_[i]->Update();
		}
	}
	void PlayState::Render()
	{
		assert(game_objects_[0] != NULL);
		Renderer::get_instance()->
			ConvertCoordinatesBasedOnCamera(
				static_cast<object::VisibleObject*>
				(game_objects_[0]));
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
				object::primitive::CapsuleParams);
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
	
}	// namespace gdh_system