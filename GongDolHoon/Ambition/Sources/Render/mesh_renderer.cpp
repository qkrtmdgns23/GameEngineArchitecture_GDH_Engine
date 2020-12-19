#include "mesh_renderer.h"

namespace ambition
{
	namespace render
	{
		MeshRenderer::MeshRenderer(MeshParams params)
			: Component(), shader_(std::make_unique<Shader>(params.vertex_path, params.fragment_path))
		{
			
		}

		MeshRenderer::MeshRenderer(const MeshRenderer& other)
		{

		}

		void MeshRenderer::Operation()
		{

		}
	}		// namespace render
}			// namespace ambition