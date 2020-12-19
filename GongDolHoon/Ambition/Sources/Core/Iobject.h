#ifndef __AMBITION_INTERFACE_OBJECT__
#define __AMBITION_INTERFACE_OBJECT__

#include "framework.h"

namespace ambition
{
	namespace core
	{
		AMBITION_INTERFACE Object abstract
		{
		public:
			virtual void		Awake()		abstract;
			virtual void		Update()	abstract;
			virtual void		Destroy()	abstract;
		protected:
			bool is_awake_ = false;
			bool is_update_ = false;
			bool is_destroy_ = false;
		};
	}		// namespace core
}			// namespace ambition

#endif		// __AMBITION_INTERFACE_OBJECT__