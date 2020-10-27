#ifndef GDH_ENGINE_INVISIBLE_OBJECT_H
#define GDH_ENGINE_INVISIBLE_OBJECT_H

#include "interface_object.h"

namespace gdh_engine {
	namespace object {
		class InvisibleObject : public InterfaceObject
		{
		public:
			InvisibleObject();
			virtual ~InvisibleObject();

			virtual void Update() override;

		private:

		};
	}	// namespace object
}	// namespace gdh_engine

#endif // GDH_ENGINE_INVISIBLE_OBJECT_H