#ifndef GDH_ENGINE_INTERFACE_OBJECT_H
#define GDH_ENGINE_INTERFACE_OBJECT_H

#include "loader_params.h"

namespace object {
	class InterfaceObject {
	public:
		InterfaceObject(const LoaderParams* params) {}
		InterfaceObject(const InterfaceObject&) = delete;
		virtual ~InterfaceObject() = default;
	};
} // namespace object

#endif // GDH_ENGINE_INTERFACE_OBJECT_H