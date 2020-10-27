#ifndef GDH_ENGINE_INTERFACE_OBJECT_H
#define GDH_ENGINE_INTERFACE_OBJECT_H

namespace gdh_engine {
	namespace object {
		class InterfaceObject {
		public:
			virtual ~InterfaceObject() {}

			virtual void Update() = 0;
		};
	} // namespace object
}	// namespace gdh_engine

#endif // GDH_ENGINE_INTERFACE_OBJECT_H