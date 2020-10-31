#ifndef GDH_ENGINE_INTERFACE_OBJECT_H
#define GDH_ENGINE_INTERFACE_OBJECT_H

#include "loader_params.h"

namespace object {
	class InterfaceObject {
	public:
		InterfaceObject(const LoaderParams* params) {}
		virtual ~InterfaceObject() {}

		virtual void Update() = 0;
		virtual void Render() const = 0;
		virtual void Clean() = 0;
	};
} // namespace object

#endif // GDH_ENGINE_INTERFACE_OBJECT_H