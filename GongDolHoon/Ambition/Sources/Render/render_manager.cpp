#include "render_manager.h"
#include "Sources/Input/input_manager.h"

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
			VAO = NULL;
			VBO = NULL;
			EBO = NULL;
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

			MeshParams temp_mesh_params;
			temp_mesh_params.vertex_path
				= "../Ambition/Sources/Render/basic_shader.vs";
			temp_mesh_params.fragment_path
				= "../Ambition/Sources/Render/basic_shader.fs";
			temp_mesh = new MeshRenderer(temp_mesh_params);

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

			glGenVertexArrays(1, &VAO);
			glGenBuffers(1, &VBO);
			glGenBuffers(1, &EBO);
			// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
			glBindVertexArray(VAO);

			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
			glEnableVertexAttribArray(0);

			// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
			glBindBuffer(GL_ARRAY_BUFFER, 0);

			// remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
			//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

			// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
			// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
			glBindVertexArray(0);

			is_awake_ = true;
		}

		void RenderManager::Update()
		{
			ambition::input::InputManager::GetInstance()->ProcessInputKeyboardPressed(window_->GetWindow());
			/* Render here */
			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

			temp_mesh->SetShaderProgram(true);

			glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
			//glDrawArrays(GL_TRIANGLES, 0, 6);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			/* Swap front and back buffers */
			glfwSwapBuffers(window_->GetWindow());

			/* Poll for and process events */
			glfwPollEvents();

			if (glfwWindowShouldClose(window_->GetWindow()))
			{
				is_update_ = true;
			}
		}

		void RenderManager::Destroy()
		{
			glDeleteVertexArrays(1, &VAO);
			glDeleteBuffers(1, &VBO);
			glDeleteBuffers(1, &EBO);
			glfwTerminate();
			is_destroy_ = true;
		}
	}		// namespace render
}			// namespace ambition