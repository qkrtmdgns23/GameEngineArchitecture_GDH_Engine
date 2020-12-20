#ifndef __AMBITION_MESH_RENDERER__
#define __AMBITION_MESH_RENDERER__

#include "framework.h"
#include "pch.h"
#include "Sources\Render\shader.h"
#include "Sources\Core\Icomponent.h"
#include "Sources\Render\Vertex\vertex_array_object.h"

namespace ambition
{
	namespace render
	{	
		AMBITION_STRUCT MeshParams
		{
			const char* vertex_path			= "";
			const char* fragment_path		= "";
		};

		AMBITION_CLASS MeshRenderer final: public core::Component
		{
		public:
			MeshRenderer(MeshParams);
			MeshRenderer(const MeshRenderer& other);
			virtual ~MeshRenderer() = default;
		public:
			virtual void Awake()	final;
			virtual void Update()	final;
			virtual void Destroy()	final;

		public:
			inline void SetShaderProgram(bool whether) const
			{
				shader_->SetUse(whether);
			}
			void		AddBufferInVAO(std::shared_ptr<Buffer> buffer, int index);
		private:
			 std::unique_ptr<Shader> shader_;
			 std::unique_ptr<VertexArrayObject> vao_;
		};
	}		// namespace render
}			// namespace ambition

#endif		// __AMBITION_MESH_RENDERER__