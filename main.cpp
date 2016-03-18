#include <iostream>
#include "TODO.hpp"
#include "TODOBuilder.hpp"

int main()
{
	
	TODOBuilder tdb;

	tdb.addFile("example.test");
	tdb.buildTodo();
	tdb.generateRaw("output.txt");	
	

	return 0;
}
