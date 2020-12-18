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
				manager->Awake();
			}
			is_awake_ = true;
		}

		void Application::Update()
		{
			int8_t is_all_update = 0;

			for (const auto& manager : managers_)
			{
				manager->Update();
				is_all_update += manager->GetIsUpdate();
			}

			if (is_all_update == managers_.size())
			{
				is_update_ = true;
			}
		}

		void Application::Destroy()
		{
			for (const auto& manager : managers_)
			{
				manager->Destroy();
			}
			is_destroy_ = true;
		}

		void Application::Add(std::shared_ptr<Manager> manager)
		{
			managers_.push_back(manager);
		}
	}	// namespace core
}		// namespace ambition