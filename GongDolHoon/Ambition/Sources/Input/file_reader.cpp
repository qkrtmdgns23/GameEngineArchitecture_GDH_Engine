#include "file_reader.h"

namespace ambition
{
	namespace input
	{
		std::string FileReader::ReadFromFile(const char* file_path) const
		{
			std::string content;
			std::ifstream file_stream(file_path);

			if (file_stream.is_open() == false)
			{
				std::cerr << file_path << " is inaccurate" << std::endl;
				return "";
			}

			std::string line = "";
			while (file_stream.eof() == false)
			{
				std::getline(file_stream, line);
				content.append(line + "\n");
			}

			file_stream.close();
			return content;
		}
	}		// namespace input
}			// namespace ambition