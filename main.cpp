#include <iostream>
#include "TODO.hpp"
#include "TODOBuilder.hpp"

int main()
{
	
	TODOBuilder tdb;

	tdb.addFile("example.test");
	if(!tdb.buildTODO())
		return -1;
	
	std::cout << tdb;	

	return 0;
}
