#ifndef GDH_ENGINE_BEHAVIOUR_H
#define GDH_ENGINE_BEHAVIOUR_H

namespace gdh_system {
	class GongDolHoonBehaviour
	{
	public:
		GongDolHoonBehaviour() = default;
		GongDolHoonBehaviour(const GongDolHoonBehaviour&) = delete;
		virtual ~GongDolHoonBehaviour() = default;

		virtual void Init() final
		{
			Start();
		}
		
		virtual void UpdatePhysics() final
		{
			FixedUpdate();
		}
		
		virtual void UpdateLogic() final
		{
			Update();
		}
		
		virtual void Render() final
		{
			RenderObject();
		}
		
		virtual void Decommiss() final
		{
			Destroy();
		}
	protected:		
		virtual void Start() = 0;
		virtual void FixedUpdate() = 0;
		virtual void Update() = 0;
		virtual void RenderObject() = 0;
		virtual void Destroy() = 0;
	};
}	// namespace gdh_system

#endif // GDH_ENGINE_BEHAVIOUR_H