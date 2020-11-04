#ifndef GDH_ENGINE_INVISIBLE_OBJECT_H
#define GDH_ENGINE_INVISIBLE_OBJECT_H

#include "interface_object.h"

namespace object {
	class LoaderParams;

	class InvisibleObject : public InterfaceObject
	{
	public:
		InvisibleObject(LoaderParams* p_param = NULL);
		InvisibleObject(const InvisibleObject& other) = delete;
		virtual ~InvisibleObject() = default;

		virtual void Update() override;
		virtual void Render() const override;
		virtual void Clean() override;
	};
}	// namespace object

#endif // GDH_ENGINE_INVISIBLE_OBJECT_H