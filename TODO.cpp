#include "TODO.hpp"

TODO::TODO() : m_file(""), m_line(0), m_comment("")
{
}

TODO::TODO(std::string file, unsigned int line, std::string comment) : m_file(file), m_line(line), m_comment(comment)
{
}

std::string TODO::getComment() const
{
	return m_comment;
}

unsigned int TODO::getLine() const
{
	return m_line;
}

std::ostream& operator<<(std::ostream &os, const TODO &todo)
{
	os << "[" << todo.getLine() << "] " << todo.getComment(); 
	return os;
}


