#include <iostream>
#include "TODO.hpp"
#include "TODOBuilder.hpp"

int main()
{
	
	TODOBuilder tdb;

	tdb.addDirectory("test");
	if(!tdb.buildTODO())
		return -1;
	
	std::cout << tdb;	

	return 0;
}
