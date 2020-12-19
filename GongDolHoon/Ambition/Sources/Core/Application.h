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
		typedef std::map<std::string, std::shared_ptr<Manager>> Managers;

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
			virtual void					 AddManager(std::string name, std::shared_ptr<Manager> manager) override;
		public:
			virtual std::shared_ptr<Manager> GetManager(std::string name) const;
		private:
			Managers managers_;
		};
	}	// namespace core
}		// namespace ambition

#endif		// __AMBITION_APPLICATION__
