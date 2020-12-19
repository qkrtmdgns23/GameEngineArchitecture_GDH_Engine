#ifndef __AMBITION_RENDER_MANAGER__
#define __AMBITION_RENDER_MANAGER__

#include "framework.h"
#include "Sources/Core/Imanager.h"
#include "Sources/Util/singleton.h"
#include "Sources/Render/window.h"
#include "mesh_renderer.h"

namespace ambition
{
	namespace render
	{
		AMBITION_STRUCT WindowInformation
		{
			const char*				title	= "Ambition Engine";
			unsigned int			width	= 1024;
			unsigned int			height	= 768;
		};

		AMBITION_CLASS RenderManager final: public core::Manager, public util::Singleton<RenderManager>
		{
		public:
									RenderManager();
									RenderManager(const RenderManager& other)	= delete;
			virtual					~RenderManager()							= default;
		protected:
			virtual void			Awake()										override;
			virtual void			Update()									override;
			virtual void			Destroy()									override;
		public:
			inline Window* GetWindow() const
			{
				return window_;
			}
		private:
			Window* window_;
			WindowInformation inform_;
			GLuint VAO;
			GLuint VBO;
			GLuint EBO;
			MeshRenderer* temp_mesh;
			
		};
	}		// namespace render
}			// namespace ambition

#endif		// __AMBITION_RENDER_MANAGER__