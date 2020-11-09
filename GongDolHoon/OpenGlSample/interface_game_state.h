#ifndef GDH_ENGINE_GAMESTATE_H
#define GDH_ENGINE_GAMESTATE_H
#include <string>
#include <vector>
#include "gdh_behaviour.h"

namespace gdh_system {
	class InterfaceGameState
	{
	public:
		InterfaceGameState() = default;
		InterfaceGameState(const InterfaceGameState& other) = delete;
		virtual ~InterfaceGameState() = default;
	protected:
		std::vector <gdh_system::GongDolHoonBehaviour*> game_objects_;

	private:
		virtual void Update() = 0;
		virtual void Render() = 0;
		virtual bool OnEnter() = 0;
		virtual bool OnExit() = 0;

		virtual std::string get_state_identity() const = 0;
	};
} // namespace gdh_system

#endif // GDH_ENGINE_GAMESTATE_H