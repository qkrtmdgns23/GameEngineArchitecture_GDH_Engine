// Input version of engine when you used.
#define GDH_ENGINE_VERSION_2

#if defined (GDH_ENGINE_VERSION_1)
#include "include/GL/glew.h"		

#include "renderer.h"
#include "texture.h"
#include "input_manager.h"
#include "visible_object.h"
#include "invisible_object.h"
#include "sphere.h"
#include "camera.h"

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "lib-vc2017/glew32.lib")
#pragma comment(lib, "lib-vc2017/glfw3.lib")

using namespace glm;
using namespace std;
using namespace gdh_engine;

int main(void)
{   
    manager::Renderer* renderer = manager::Renderer::get_instance();
    object::Camera* camera = object::Camera::get_instance();
    object::primitive::Sphere* primitive_sphere = new  object::primitive::Sphere;

    primitive_sphere->SetObjectPosition(glm::vec3(0.f, 0.f, 0.f));
    primitive_sphere->SetObjectRotation(glm::vec3(45.0f, 45.0f, 0.0f));
    camera->set_camera_position(glm::vec3(0.f, 0.f, 10.0f));

	while (renderer->IsWindowShouldClose() == false)
	{
		manager::InputManager::get_instance()->ProcessInput(renderer->get_engine_window());
        renderer->ConvertCoordinatesForRender(camera, primitive_sphere);
        primitive_sphere->RotateObject(glm::vec3(glfwGetTime(), 0.f, 0.f));
        renderer->Render(primitive_sphere);
	}
    renderer->ShutDown();
    delete primitive_sphere;

    return 0;
}
#endif // GDH_ENGINE_VERSION_01

#if defined (GDH_ENGINE_VERSION_2)

#include "cstdio"
#include "game.h"
#include "error_manager.h"

using namespace system;

int main(void)
{
    if (Game::get_instance()->InitRenderingEnvironment
        ("GDH_ENGINE_VERSION_2", 3, 3, 1028, 724))
    {
        while (Game::get_instance()->SystemRunning())
        {
            Game::get_instance()->HandleEvents();
            Game::get_instance()->Update();
            Game::get_instance()->Render();
        }
    }
    else
    {
        fprintf(stderr, "Error Occured: %d", ErrorType::kInitFailed);
        return -1;
    }
    Game::get_instance()->Exit();

    return 0;
}
#endif // GDH_ENGINE_VERSION_02