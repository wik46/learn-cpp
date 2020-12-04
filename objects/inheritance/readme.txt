Author: Wikus Jansen van Rensburg
Description: Studying one of Object Orientated Programmings paradiagms:
Date: December 3, 2020.
Learning Resource: GeeksforGeeks.org		
	Guidance on how to use this directory.
	
	Using the Cmake build system.
		- Type in the command make followed by the name of the
		  file without the .cpp extention.	

	=================================
	Inheritance:
	=================================

	I.) Constructor and destructor timing:
		- Remember that the parent constructor is called from the 
		  initializer list of the child. This parent will be constructed
		  first, before moving to the body of the child constructor.
		- Destructors are always called in reverse order than the constructors.
