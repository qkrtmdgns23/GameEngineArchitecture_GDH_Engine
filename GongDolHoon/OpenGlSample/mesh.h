#ifndef GDH_ENGINE_MESH_H
#define GDH_ENGINE_MESH_H

#include <vector>
#include <string>
// library
#include "glm/glm.hpp"
#include "include/GLFW/glfw3.h" 

// custom header
#include "interface_component.h"

namespace gdh_engine {
	namespace object {
		enum class AttribDataType;
		typedef struct VertexInformation Vertex;

		class Mesh : public InterfaceComponent
		{
		public:
			Mesh(std::string obj_path);
			Mesh(const char* obj_path);
			~Mesh();

			void SetUpMesh();
			virtual void SetActive() final;
			virtual void SetUnActive() final;

			GLuint get_vertex_array_object_identity() const
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
			GLuint get_vertex_buffer_object_identity() const
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
			unsigned int get_num_of_vertices() const
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
			bool get_is_mesh_active() const
			{
				return is_mesh_active_;
			}
		private:
			void GenerateAndBindVertexArrayObject();
			void GenerateAndBindVertexBufferObject();
			//void EnableFloatTypeVertexAttribArray(const int location,
			//	const int vertex_attrib_size, const int stride, const int offset,
			//	AttribDataType data_type, bool is_normalization);
			void UnbindVertexBufferObject();
			void UnbindVertexArrayObject();

			GLuint vertex_array_object_identity_;
			GLuint vertex_buffer_object_identity_;

			std::vector<glm::vec3> vertices_;
			std::vector<glm::vec3> normals_;
			std::vector<glm::vec2> uvs_;

			Vertex* vertex_array_;
			unsigned int num_of_vertices_;

			// this is value for prevent invoke sequence violation.
			bool is_vertex_array_object_invoke_;
			bool is_mesh_active_;
		};

		enum class AttribDataType
		{
			kGdhByte = GL_BYTE,
			kGdhUnsignedByte = GL_UNSIGNED_BYTE,
			kGdhShort = GL_SHORT,
			kGdhUnsignedShort = GL_UNSIGNED_SHORT,
			kGdhInt = GL_INT,
			kGdhUnsignedInt = GL_UNSIGNED_INT,
			kGdhFloat = GL_FLOAT,
			kGdh2Bytes = GL_2_BYTES,
			kGdh3Bytes = GL_3_BYTES,
			kGdh4Bytes = GL_4_BYTES,
			kGdhDouble = GL_DOUBLE,
		};

		typedef struct VertexInformation
		{
			glm::vec3 position;
			glm::vec2 texture_coordinate;
			glm::vec3 normal;
		}Vertex;
	} // namespace object
} // namespace gdh_engine

#endif // GDH_ENGINE_MESH_H