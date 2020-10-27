#ifndef GDH_ENGINE_INTERFACE_COMPONENT_H
#define GDH_ENGINE_INTERFACE_COMPONENT_H

namespace object
{
	namespace component {
		class InterfaceComponent {
		public:
			virtual ~InterfaceComponent() {}

			virtual void SetActive() = 0;
			virtual void SetUnActive() = 0;
		};
	} // namespace component 
}	// namespace object

#endif // GDH_ENGINE_COMPONENT_INTERFACE_H