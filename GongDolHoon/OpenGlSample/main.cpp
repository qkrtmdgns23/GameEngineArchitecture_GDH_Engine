// library
#include "include/GL/glew.h"		

// custom header
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
