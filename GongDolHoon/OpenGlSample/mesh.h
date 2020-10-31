#ifndef GDH_ENGINE_MESH_H
#define GDH_ENGINE_MESH_H

#include <vector>
#include <string>
#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h" 
#include "glm/glm.hpp"

#include "interface_component.h"
#include "loader_params.h"

namespace object {
	namespace component {
		class Mesh : public InterfaceComponent
		{
		public:
		#pragma region CONSTRUCTOR_DESTRUCTOR
			Mesh(std::string obj_path);
			Mesh(const char* obj_path);
			~Mesh();
		#pragma endregion
			inline virtual void SetActive() final;
			inline virtual void SetUnActive() final;
			inline bool IsMeshActive() const;
			void SetUpMesh();
			
			inline unsigned int get_num_of_vertices() const;
			inline GLuint get_vertex_buffer_object_identity() const;
			inline GLuint get_vertex_array_object_identity() const;
		private:
			Mesh(const Mesh& other) = delete;

		#pragma region RELATED_WITH_OPENGL
			void GenerateAndBindVertexArrayObject();
			void GenerateAndBindVertexBufferObject();
			inline void UnbindVertexBufferObject();
			inline void UnbindVertexArrayObject();

			GLuint vertex_array_object_identity_;
			GLuint vertex_buffer_object_identity_;
		#pragma endregion
		#pragma region VERTICLES
			std::vector<glm::vec3> vertices_;
			std::vector<glm::vec3> normals_;
			std::vector<glm::vec2> uvs_;
			Vertex* vertex_array_;
			unsigned int num_of_vertices_;
		#pragma endregion
			bool is_vertex_array_object_invoke_;
			bool is_mesh_active_;
		};
		void Mesh::SetActive()
		{
			is_mesh_active_ = true;
		}
		void Mesh::SetUnActive()
		{
			is_mesh_active_ = false;
		}
		bool Mesh::IsMeshActive() const
		{
			assert(false <= is_mesh_active_ <= true);
			return is_mesh_active_;
		}
		void Mesh::UnbindVertexBufferObject()
		{
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
		void Mesh::UnbindVertexArrayObject() 
		{
			glBindVertexArray(0);
		}
		unsigned int Mesh::get_num_of_vertices() const
		{
			if (is_mesh_active_)
			{
				return num_of_vertices_;
			}
			else
			{
				return 0;
			}
		}
		GLuint Mesh::get_vertex_array_object_identity() const
		{
			if (is_mesh_active_)
			{
				return vertex_array_object_identity_;
			}
			else
			{
				return 0;
			}
		}
		GLuint Mesh::get_vertex_buffer_object_identity() const
		{
			if (is_mesh_active_)
			{
				return vertex_buffer_object_identity_;
			}
			else
			{
				return 0;
			}

		}
	}	// namespace component
}	// namespace object
#endif // GDH_ENGINE_MESH_H