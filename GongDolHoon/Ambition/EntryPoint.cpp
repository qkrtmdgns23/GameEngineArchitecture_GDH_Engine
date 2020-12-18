#include "pch.h"
#include "EntryPoint.h"
#include "Sources/Render/window.h"
#include "Sources/Core/Imanager.h"
#include "Sources/Render/render_manager.h"
#include "Sources/Core/Application.h"

using namespace ambition::render;

int EntryPoint::Test()
{
	ambition::core::Manager* application = ambition::core::Application::GetInstance();

	std::shared_ptr<ambition::core::Manager> render = std::make_shared<RenderManager>();
	application->Add(render);

	application->Operation();

	return 0;
}