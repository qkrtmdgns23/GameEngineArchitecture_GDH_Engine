#ifndef __AMBITION_APPLICATION__
#define __AMBITION_APPLICATION__

#include "framework.h"
#include "pch.h"
#include "Imanager.h"
#include "Sources/Util/singleton.h"

namespace ambition
{
	namespace core
	{
		AMBITION_CLASS Application: public Manager, public util::Singleton<Application>
		{
		public:
					Application();
					Application(const Application& other) = delete;
			virtual ~Application() = default;
		protected:
			virtual void Awake()	override;
			virtual void Update()	override;
			virtual void Destroy()	override;
		// Composite & Template Method Pattern
		protected:
			virtual void	Add(std::shared_ptr<Manager> manager) override;
		private:
			std::list<std::shared_ptr<Manager>> managers_;
		};
	}	// namespace core
}		// namespace ambition

#endif		// __AMBITION_APPLICATION__
