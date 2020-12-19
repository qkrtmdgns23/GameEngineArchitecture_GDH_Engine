#ifndef __AMBITION_INTERFACE_MANAGER__
#define __AMBITION_INTERFACE_MANAGER__

#include "framework.h"
#include "pch.h"

namespace ambition
{
	namespace core
	{
		AMBITION_INTERFACE Manager abstract
		{
		public:
					Manager()						= default;
					Manager(const Manager& other)	= delete;
			virtual	~Manager()						= default;
		public:
			virtual void	Operation()		final
			{
				if (is_awake_ == false)
				{
					Awake();
				}
				while (is_update_ == false)
				{
					Update();
				}
				if (is_destroy_ == false)
				{
					Destroy();
				}
			}
		public:
			virtual void					 AddManager(std::string name, std::shared_ptr<Manager> manager) {}
			virtual std::shared_ptr<Manager> Get(unsigned int index) {return nullptr;}
			virtual void					 Awake()			abstract;
			virtual void					 Update()			abstract;
			virtual void					 Destroy()			abstract;
			inline bool						 GetIsUpdate()		const
			{
				return is_update_;
			}
		protected:
			bool			is_awake_		= false;
			bool			is_update_		= false;
			bool			is_destroy_		= false;
		};
	}		// namespace core
}			// namespace ambition

#endif		// __AMBITION_INTERFACE_MANAGER__