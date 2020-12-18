#ifndef __AMBITION_SINGLETON__
#define __AMBITION_SINGLETON__

#include "framework.h"

namespace ambition
{
	namespace util
	{	
		template <typename SClass>
		AMBITION_CLASS Singleton
		{
		public:
			static SClass*			GetInstance()
			{
				if (instance_ == nullptr)
				{
					instance_ = new SClass;
				}
				return instance_;
			}
			
			static void				DestroyInstance()
			{
				if (instance_)
				{
					delete instance_;
					instance_ = nullptr;
				}
			}
		protected:
			Singleton() = default;
			Singleton(const Singleton& other) = delete;
			~Singleton() = default;
		private:
			static SClass*			instance_;
		};
		
		template <typename SClass> 
		SClass* Singleton<SClass>::instance_ = nullptr;
	}	// namespace util
}		// namespace ambition
#endif	// __AMBITION_SINGLETON__