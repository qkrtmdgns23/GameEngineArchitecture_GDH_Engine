#include <cstdio>

#include "play_state.h"
#include "renderer.h"
#include "interface_object.h"
#include "visible_object.h"
#include "gdh_behaviour.h"
#include "time.h"

namespace gdh_system {
	const std::string PlayState::state_id_ = "PLAY";
	PlayState* PlayState::instance_ = NULL;

	bool PlayState::OnEnter()
	{
		fprintf(stdout, "Enter On PlayState\n");
		object::VisibleObject* sphere
			= new object::VisibleObject(new
				object::primitive::SphereParams);
		game_objects_.push_back(sphere);
		for (size_t i = 0; i < game_objects_.size(); ++i)
		{
			game_objects_[i]->Init();
		}
		return true;
	}

	void PlayState::Update()
	{
		assert(game_objects_[0] != NULL);
		if (Time::get_instance()->IsLogicUpdatePossible() == true)
		{
			for (size_t i = 0; i < game_objects_.size(); ++i)
			{
				game_objects_[i]->UpdateLogic();
			}
		}
		if (Time::get_instance()->IsPhysicsUpdatePossible() == true)
		{
			for (size_t i = 0; i < game_objects_.size(); ++i)
			{
				game_objects_[i]->UpdatePhysics();
			}
		}
	}
	void PlayState::Render()
	{
		assert(game_objects_[0] != NULL);
		Renderer::get_instance()->
			ConvertCoordinatesBasedOnCamera(
				static_cast<object::VisibleObject*>
				(game_objects_[0]));
		
		if (Time::get_instance()->IsRenderUpdatePossible() == true)
		{
			for (size_t i = 0; i < game_objects_.size(); ++i)
			{
				game_objects_[i]->Render();
			}
		}
	}

	bool PlayState::OnExit()
	{
		fprintf(stdout, "Exit On ExitState\n");
		for (size_t i = 0; i < game_objects_.size(); ++i)
		{
			game_objects_[i]->Decommiss();
		}
		game_objects_.clear();
		return true;
	}

}	// namespace gdh_system