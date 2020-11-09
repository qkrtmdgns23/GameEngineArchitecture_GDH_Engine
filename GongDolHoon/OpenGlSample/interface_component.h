#ifndef GDH_ENGINE_INTERFACE_COMPONENT_H
#define GDH_ENGINE_INTERFACE_COMPONENT_H

namespace object {
	namespace component {
		class InterfaceComponent {
		public:
			InterfaceComponent() = default;
			InterfaceComponent(const InterfaceComponent& other)
				= delete;
			virtual ~InterfaceComponent() = default;

			virtual void SetActive() = 0;
			virtual void SetUnActive() = 0;
		};
	} // namespace component 
}	// namespace object

#endif // GDH_ENGINE_COMPONENT_INTERFACE_H