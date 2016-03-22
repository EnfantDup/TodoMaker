#include "TODOBuilder.hpp"

TODOBuilder::TODOBuilder()
{
}

void TODOBuilder::addFile(std::string file)
{
	//Check if file isn't already added
	auto it = m_TODOList.find(file);

	if(it == m_TODOList.end())
		m_TODOList.insert(TODOMap::value_type(file, TODOVector()));
} 

bool TODOBuilder::addDirectory(std::string directory)
{
	//Create path
	boost::filesystem::path dir_path(directory);

	//Directory need to exist
	if(!boost::filesystem::exists(dir_path))
	{
		std::cerr << "Directory " << directory << " doesn't exist" << std::endl;
		return false;
	}
	else
	{
		boost::filesystem::directory_iterator end_it;
		//Iterate all files
		for(boost::filesystem::directory_iterator it(dir_path); it != end_it; it++)
		{
			//Add file or directory
			if(!boost::filesystem::is_directory(it->status()))
			{
				addFile(it->path().string());
			}
			else
			{
				addDirectory(it->path().string());
			}
		}
	}
	return true;
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
			std::string multipleLineComment;
			bool isMultipleLineComment = false;
			unsigned int MCLine = 0;

			//Read every line
			while(getline(file, line))
			{
				//Multiple line comment actually reading ?
				if(isMultipleLineComment)
				{
					std::size_t pos = line.find("ETODO");
					
					//If end of Multiple TODO not found, just add the line
					if(pos == std::string::npos)
					{
						multipleLineComment += "\n";
						multipleLineComment += line;
					}
					else
					{
						//End of multiple line TODO, push the TODO
						isMultipleLineComment = false;
						it->second.push_back(TODO(it->first, MCLine, multipleLineComment));	
						multipleLineComment = "";
					}
				}
				else
				{
					//Check for multiple line TODO
					std::size_t pos = line.find("BTODO");
					
					//If so, set boolean to true
					if(pos != std::string::npos)
					{
						multipleLineComment = line.substr(pos+5);
						isMultipleLineComment = true;
						MCLine = lineNumber;
					}
					else
					{
 						//Else check for simple line TODO
						pos = line.find("TODO");
				
						//If TODO statement found
						if(pos != std::string::npos)
						{
							//Get from TODO to then end
							//Remove the 4 char of TODO
							std::string comment = line.substr(pos+4);
							//Add statement to the list
							it->second.push_back(TODO(it->first, lineNumber, comment));
						}
					}
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

