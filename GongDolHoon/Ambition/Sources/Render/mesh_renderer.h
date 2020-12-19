#ifndef __AMBITION_MESH_RENDERER__
#define __AMBITION_MESH_RENDERER__

#include "framework.h"
#include "pch.h"
#include "Sources\Render\shader.h"
#include "Sources\Core\Icomponent.h"

namespace ambition
{
	namespace render
	{	
		AMBITION_STRUCT MeshParams
		{
			const char* vertex_path = "";
			const char* fragment_path = "";
		};

		AMBITION_CLASS MeshRenderer final: public core::Component
		{
		public:
			MeshRenderer(MeshParams);
			MeshRenderer(const MeshRenderer& other);
			virtual ~MeshRenderer() = default;
		public:
			virtual void Operation() final;
			inline void SetShaderProgram(bool whether) const
			{
				shader_->SetUse(whether);
			}
		private:
			 std::unique_ptr<Shader> shader_;
		};
	}		// namespace render
}			// namespace ambition

#endif		// __AMBITION_MESH_RENDERER__