#ifndef GDH_ENGINE_INTERFACE_COMPONENT_H
#define GDH_ENGINE_INTERFACE_COMPONENT_H

namespace gdh_engine {
	namespace object
	{
		class InterfaceComponent {
		public:
			virtual ~InterfaceComponent() {}

			virtual void SetActive() = 0;
			virtual void SetUnActive() = 0;
		};
	}	// namespace object
}	// namespace gdh_engine

#endif // GDH_ENGINE_COMPONENT_INTERFACE_H