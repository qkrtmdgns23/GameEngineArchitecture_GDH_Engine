#ifndef __AMBITION_INPUT_MANAGER__
#define __AMBITION_INPUT_MANAGER__

#include "framework.h"
#include "Sources/Core/Imanager.h"
#include "Sources/Util/singleton.h"
#include "Sources/Render/render_manager.h"

namespace ambition
{
	namespace input
	{
		AMBITION_CLASS InputManager final: public core::Manager, public util::Singleton<InputManager>
		{
		public:
					InputManager();
					InputManager(const InputManager& other) = delete;
			virtual ~InputManager()							= default;
		// Manager Override Function
		public:
			virtual void	Awake()		override;
			virtual void	Update()	override;
			virtual void	Destroy()	override;
		public:
			void	ProcessInputKeyboardPressed(GLFWwindow* window);
		};
	}		// namespace input
}			// namespace ambition

#endif		// __AMBITION_INPUT_MANAGER__