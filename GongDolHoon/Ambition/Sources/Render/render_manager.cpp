#include "render_manager.h"
#include "Sources/Input/input_manager.h"
#include "Vertex/attribute_buffer.h"
#include "Sources/Render/Vertex/Ibuffer.h"

namespace ambition
{
	namespace render
	{
		RenderManager::RenderManager()
			:window_(nullptr), inform_()
		{
			is_awake_ = false;
			is_update_ = false;
			is_destroy_ = false;
		}

		void RenderManager::Awake()
		{
			if (!glfwInit())
			{
				std::cerr << "GLFW Init Failed." << std::endl;
				glfwTerminate();
			}
			window_ = new Window(inform_.title, inform_.width, inform_.height);

			glewExperimental = true;
			if (glewInit() != GLEW_OK)
			{
				std::cerr << "GLEW Init Failed." << std::endl;
				glfwTerminate();
			}

			MeshParams square_mesh_params;
			square_mesh_params.vertex_path
				= "../Ambition/Resources/Shaders/Vertex/basic_shader.vs";
			square_mesh_params.fragment_path
				= "../Ambition/Resources/Shaders/Fragment/basic_shader.fs";
			temp_mesh = new MeshRenderer(square_mesh_params);

			float vertices[] = {
				 0.5f,  0.5f, 0.0f,  // top right
				 0.5f, -0.5f, 0.0f,  // bottom right
				-0.5f, -0.5f, 0.0f,  // bottom left
				-0.5f,  0.5f, 0.0f   // top left 
			};
			unsigned int indices[] = {  // note that we start from 0!
				0, 1, 3,  // first Triangle
				1, 2, 3   // second Triangle
			};

			square_vao_ = std::make_unique<VertexArrayObject>();
			std::shared_ptr<Buffer> vertex_position_ = std::make_shared<AttributeBuffer>(vertices, 0, 3, 12);
			
			square_vao_->SetBind(true);;
			square_ebo_ = std::make_unique<IndexBuffer>(indices, 6);
			square_vao_->AddBuffer(vertex_position_, 0);
			
			vertex_position_->SetBind(true);

			
			square_vao_->SetBind(true);

			is_awake_ = true;
		}

		void RenderManager::Update()
		{
			ambition::input::InputManager::GetInstance()->ProcessInputKeyboardPressed(window_->GetWindow());
			
			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

			temp_mesh->SetShaderProgram(true);

			square_vao_->SetBind(true); 
			
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			glfwSwapBuffers(window_->GetWindow());

			glfwPollEvents();

			if (glfwWindowShouldClose(window_->GetWindow()))
			{
				is_update_ = true;
			}
		}

		void RenderManager::Destroy()
		{
			glfwTerminate();
			is_destroy_ = true;
		}
	}		// namespace render
}			// namespace ambition