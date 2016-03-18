#ifndef DEF_TODO_BUILDER
#define DEF_TODO_BUILDER

#include "TODO.hpp"
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <boost/filesystem.hpp>

typedef std::vector<TODO> TODOVector;
typedef std::map<std::string, TODOVector> TODOMap;

class TODOBuilder
{
	public:
		TODOBuilder();
		void addFile(std::string file);
		bool addDirectory(std::string directory);
		bool buildTODO();
		bool generateRaw(std::string outputFile);
		const TODOMap & getTODOList() const;

	private:
		//Map of TODO linked to a filename
		TODOMap  m_TODOList;
};


std::ostream& operator<<(std::ostream& os, const TODOBuilder& tb);

#endif

