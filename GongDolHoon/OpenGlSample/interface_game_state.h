#ifndef GDH_ENGINE_GAMESTATE_H
#define GDH_ENGINE_GAMESTATE_H
#include <string>
#include <vector>
#include "interface_object.h"

namespace system_2 {
	class InterfaceGameState
	{
	protected:
		std::vector <object::InterfaceObject*> game_objects_;

	private:
		virtual void Update() = 0;
		virtual void Render() = 0;
		virtual bool OnEnter() = 0;
		virtual bool OnExit() = 0;

		virtual std::string get_state_identity() const = 0;
	};
} // namespace system_2

#endif // GDH_ENGINE_GAMESTATE_H