#ifndef __AMBITION_INTERFACE_BUFFER__
#define __AMBITION_INTERFACE_BUFFER__

#include "framework.h"
#include "pch.h"

namespace ambition
{
	namespace render
	{
		AMBITION_INTERFACE Buffer abstract
		{
		public:
			Buffer() = default;
			Buffer(const Buffer& other) = delete;
			virtual ~Buffer() = default;
		public:
			virtual void	SetBind(bool whether) const abstract;
			virtual GLuint	GetAttribute() const abstract;
			virtual GLuint	GetAttributeSize() const abstract;
		protected:
			GLuint id_;
			GLuint size_;
		};
	}
}

#endif		// __AMBITION_BUFFER__