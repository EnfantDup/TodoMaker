#ifndef DEF_TODO
#define DEF_TODO

#include <string>
#include <iostream>

class TODO
{
	public:
		TODO();
		TODO(std::string file, unsigned int line, std::string comment);
		std::string getComment() const;
		unsigned int getLine() const;	
	private:
		std::string m_file;
		unsigned int m_line;
		std::string m_comment;
};

std::ostream& operator<<(std::ostream &os, const TODO &todo);

#endif 

