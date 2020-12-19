#ifndef __AMBITION_FILE_READER__
#define __AMBITION_FILE_READER__

#include "framework.h"
#include "pch.h"
#include "Sources/Util/singleton.h"

namespace ambition
{
	namespace input
	{
		AMBITION_CLASS FileReader: public util::Singleton<FileReader>
		{
		public:
					FileReader() = default;
					FileReader(const FileReader& other) = delete;
			virtual ~FileReader() = default;
		public:
			std::string ReadFromFile(const char* file_path) const;
		};
	}		// namespace input
}			// namespace ambition

#endif		// __AMBITION_FILE_READER__