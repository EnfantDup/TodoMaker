#ifndef DEF_TODO_BUILDER
#define DEF_TODO_BUILDER

#include "TODO.hpp"
#include <vector>
#include <map>
#include <fstream>
#include <iostream>

typedef std::vector<TODO> TODOVector;
typedef std::map<std::string, TODOVector> TODOMap;

class TODOBuilder
{
	public:
		TODOBuilder();
		void addFile(std::string file);
		bool buildTODO();
		bool generateRaw(std::string outputFile);

	private:
		//Map of TODO linked to a filename
		TODOMap  m_TODOList;
};

#endif

