#ifndef __AMBITION_INTERFACE_COMPONENT__
#define __AMBITION_INTERFACE_COMPONENT__

#include "framework.h"

namespace ambition
{
	namespace core
	{
		AMBITION_INTERFACE Component abstract
		{
		public:
			Component() = default;
			Component(const Component& other)
			{
				is_active_ = other.is_active_;
			}
			virtual ~Component() = default;
		public:
			inline virtual void SetActive(bool active) final
			{
				is_active_ = active;
			}
			virtual void		Awake()				abstract;
			virtual void		Update()			abstract;
			virtual void		Destroy()			abstract;
		protected:
			bool is_active_ = false;
		};
	}		// namespace core
}			// namespace ambition

#endif		// __AMBITION_INTERFACE_COMPONENT__