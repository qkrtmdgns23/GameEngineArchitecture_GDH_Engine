#include "Application.h"

namespace ambition
{
	namespace core
	{
		Application::Application()
		{
			is_awake_ = false;
			is_update_ = false;
			is_destroy_ = false;
		}

		void Application::Awake()
		{
			for (const auto& manager : managers_)
			{
				manager.second->Awake();
			}
			is_awake_ = true;
		}

		void Application::Update()
		{
			int8_t is_all_update = 0;

			for (const auto& manager : managers_)
			{
				manager.second->Update();
			}

			if (GetManager("RENDER")->GetIsUpdate())
			{
				is_update_ = true;
			}
		}

		void Application::Destroy()
		{
			for (const auto& manager : managers_)
			{
				manager.second->Destroy();
			}
			is_destroy_ = true;

			
		}

		void Application::AddManager(std::string name, std::shared_ptr<Manager> manager)
		{
			managers_.insert(Managers::value_type(name, manager));
		}

		std::shared_ptr<Manager> Application::GetManager(std::string name) const
		{
			return managers_.find(name)->second;
		}
	}	// namespace core
}		// namespace ambition