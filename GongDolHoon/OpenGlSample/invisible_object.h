#ifndef GDH_ENGINE_INVISIBLE_OBJECT_H
#define GDH_ENGINE_INVISIBLE_OBJECT_H

#include "interface_object.h"

namespace object {
	class LoaderParams;

	class InvisibleObject : public InterfaceObject
	{
	public:
		InvisibleObject(LoaderParams* p_param = NULL);
		virtual ~InvisibleObject();

		virtual void Update() override;
	};
}	// namespace object

#endif // GDH_ENGINE_INVISIBLE_OBJECT_H