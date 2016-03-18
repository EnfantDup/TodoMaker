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

const TODOMap& TODOBuilder::getTODOList() const
{
	return m_TODOList;
}

std::ostream& operator<<(std::ostream& os, const TODOBuilder& tb)
{
	const TODOMap& todoList = tb.getTODOList();

	//Parcours la liste des fichiers
	for(auto fileIT = todoList.begin(); fileIT != todoList.end(); fileIT++)
	{
		os << "Fichier " << fileIT->first << " :" << std::endl;

		//Parcours des TODO d'un fichier
		for(auto todoIT = fileIT->second.begin(); todoIT != fileIT->second.end(); todoIT++)
		{
			os << "-" << *todoIT << std::endl;
		}
	}


	return os;
}

