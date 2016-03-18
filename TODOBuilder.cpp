#include "TODOBuilder.hpp"

TODOBuilder::TODOBuilder()
{
}

void TODOBuilder::addFile(std::string file)
{
	m_TODOList.insert(TODOMap::value_type(file, TODOVector()));
} 

bool TODOBuilder::buildTODO()
{
	std::ifstream file;
	std::string line;
	bool success = true; //If an error occur

	//For every file to watch
	for(auto it = m_TODOList.begin(); it != m_TODOList.end(); it++)
	{	
		//Open current file
		file.open(it->first);
		if(file.good())
		{
			unsigned int lineNumber = 1;
			//Read every line
			while(getline(file, line))
			{
				std::size_t pos = line.find("TODO");
				
				//If TODO statement found
				if(pos != std::string::npos)
				{
					//Get from TODO to then end
					std::string comment = line.substr(pos);
					//Add statement to the list
					it->second.push_back(TODO(it->first, lineNumber, comment));
				}
				lineNumber++;
			}
			file.close();
		}
		else
		{
			success = false;
			std::cerr << "Can't open " << it->first << std::endl;
		}
	}

	return success;
}

bool TODOBuilder::generateRaw(std::string outputFile)
{
}
