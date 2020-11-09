#ifndef GDH_ENGINE_INVISIBLE_OBJECT_H
#define GDH_ENGINE_INVISIBLE_OBJECT_H

#include "interface_object.h"
#include "gdh_behaviour.h"

namespace object {
	class LoaderParams;

	class InvisibleObject : public InterfaceObject
		, public gdh_system::GongDolHoonBehaviour
	{
	public:
		InvisibleObject(LoaderParams* p_param = NULL);
		InvisibleObject(const InvisibleObject& other) = delete;
		virtual ~InvisibleObject() = default;

		virtual void Start() override;
		virtual void FixedUpdate() final;
		virtual void Update() override;
		virtual void RenderObject() final;
		virtual void Destroy() override;
	};
}	// namespace object

#endif // GDH_ENGINE_INVISIBLE_OBJECT_H