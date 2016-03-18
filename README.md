# TodoMaker
A tool to generate a todo list out of a group of file. It can be used with code source files (like .cpp).

Requirements
------------

The boost library is needed in order build the program. You can install boost in most distribution using apt-get :
	sudo apt-get install libboost-all-dev

You can then run the Makefile to build the program :
	make
	
Usage
-----

Wherever you notice something to be done (a todo), you can simply add a TODO directive. Example :

	TODO Add a collision system

For multiple line TODO, start with BTODO (for Begin Todo) et end with ETODO (End Todo).

	BTODO 
	Multiple checks need to be done :
	- Pointers Validity
	- No null parameters
	ETODO

It is done to be compatible with every langages comments.

# Credits
Writen by Nicolas DUPIN
