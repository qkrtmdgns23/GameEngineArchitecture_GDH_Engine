#include "mesh_renderer.h"

namespace ambition
{
	namespace render
	{
		MeshRenderer::MeshRenderer(MeshParams params)
			: Component(), shader_(std::make_unique<Shader>(params.vertex_path, params.fragment_path))
			, vao_(std::make_unique<VertexArrayObject>())
		{
			
		}

		MeshRenderer::MeshRenderer(const MeshRenderer& other)
		{

		}

		void MeshRenderer::Awake()
		{

		}

		void MeshRenderer::Update()
		{

		}

		void MeshRenderer::Destroy()
		{

		}

		void MeshRenderer::AddBufferInVAO(std::shared_ptr<Buffer> buffer, int index)
		{
			vao_->AddBuffer(buffer, index);
		}

	}		// namespace render
}			// namespace ambition