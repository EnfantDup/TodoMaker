#ifndef DEF_TODO
#define DEF_TODO

#include <string>

class TODO
{
	public:
		TODO();
		TODO(std::string file, unsigned int line, std::string comment);

	private:
		std::string m_file;
		unsigned int m_line;
		std::string m_comment;
};

#endif 

