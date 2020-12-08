===================================================================================================		
Author: Wikus Jansen van Rensburg.
Date: December 8, 2020.
Description: This is a brief summaray of how to input and output data in C++
Header file for file streams: <fstream>
===================================================================================================		

===================================================================================================		
How to work with files in C++: Storing data (output) and retrieving data (input)
===================================================================================================		

****************
Two types of I/O
****************
1. Console I/O: keyboard/monitor
2. File I/O: ASCII files store on hardisk.


We will investigate the second type of I/O, File I/O.
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Streams are objects that our program used to communicate with the operating system.
We use them to take input/ and produces output.

	* An example of a stream object is std::cout (type std::ostream) and 
		std::cin (type std::istream).
	* These stream objects interact with the operating system.
		
	* Although this is very helpful while the program is running, we still need 
		a way to save data when our program is shutdown. We want to use the data later. 
		We store this files on the hard disk of the computer. 
	* For this we need new types of stream objects, callled file stream objects.
		* 1. std::ifstream (intherits from std::istream, operator used '<<')
			- used only to take input from a file.
		* 2. std::ofstream (inherits from std::ostream, operator used '<<')
			- used only to send output to a file.
		* 3. std::fstream (std::ifstream + std::ofstream = std::fstream)
			- Can be used to take input from a file or send ouput to a file.
		
		* Remember that a text file is just a sequence of ASCII charaters.
			- When you consider outputting data to a file, think of it as outputting
			  data to the console usinf std::cout << 'data', but instead of using
			  the std::ostream object you now use 
			  the std::ofstream or std::fstream object. 
	** Remarks:
		- You can only use one stream object at a time.
		- Your file must be in the same directory as the source code or you need
		  to specify the relative path.
	
	I: Opening files for input:
	-----------------------------------------
		- a. It is very important that you ensure the file is correctly opened using .is_open().
		- b. Examen the format of the file closely to see how to take the data in.
		-


	II: Opening files for output:
	-----------------------------------------
		- a. Opening a file with the standard std::ios::out, will create a file of the name
		     specified if none exist, or it will override the data in a file that has the exact name.
		- b.



	III: Member functions of fstream objects:
	-----------------------------------------

	IV: Modes to open a file:
	-----------------------------------------
		* These are the different ways that you open a file.
		* Example: Lets say you create a fstream object with the following line.
					'std::fstream my_file;'
			   - Now you can chose to open the file using my_file.open().
			   - The member function .open() takes two parameters.
				1. The name of the file as a c-style string, in C++11 you can 
					pass a string.
				2. The mode that you want to open the file with. (how you want to open the file)

		@ std::ios::in  : When  I want to open a file and read (take input) from the file.
		@ std::ios::out	: When I want to open a file and output data to it. 
				  - Creates a file if none exist or overrided existing file.
		- These to modes that you use to open a file can be augmented by the following using
		  the '|' operator.
		- Example: Open a file to append data at the end of the file.
			my_file.open("file_name.txt", std::ios::out | std::ios::app);		

		@ std::ios::app : Append data to the end of the file.	
		@ std::ios::ate : Open the file 'A't 'T'he 'E'nd.
		@ std::ios::bin : Open the file as a binary file.
	
	V: Errors with opening files:
	-------------------------------
	- When will my file not open?
		* When you already have an stream object open, you can only have one open at a time.
		* When some combination of the open modes don't work together.
	- Solution:
		* Test if the file is open using the member function .is_open()
			- returns true if file is opened successfully, and false otherwise.
			- This actually returns state flags of the objects, but it is not
				needed for this summary.
	
	VI: A few types of seperation characters (file parsing):
	-----------------------------------------
	- Knowing how the file that you want to read (input) data from is critical.
	- Here as some examples of basic seperation charaters.
		* a. space ' ': You can use .geline() to read data from this type of file format.
		* b. commas ',' : You can use .getline(std::string, ',') to read data from this file format.
		* c. newline '\n' : This one is most user friendly and encouraged to use.
				    Be careful, different OS's have different ways to store it.
		* d. tab '\t':  
			
	VII: FIle pointer:
	------------------
	- See example4 directory.
		Input stream:
			- Has a 'get' pointer.
			- .seekg(x, y)
				* x: Will be the number of byte the file pointer moves relative to the 
					position specified in the second argument of the member function seekg().
				* x: a variable of type int that represent the size in bites of the direction to move.
				* y: std::ios::beg (from the begining of the file.)
				     std::ios::end (from the end of the file.)
				     std::ios::cur (from the current position of the get pointer.)
		Output stream:	
			- Has a 'put' pointer.
			- .seekp(x, y)
				* x: Will be the number of byte the file pointer moves relative to the 
					position specified in the second argument of the member function seekp().
				* x: a variable of type int that represent the size in bites of the direction to move.
				* y: std::ios::beg (from the begining of the file.)
				     std::ios::end (from the end of the file.)
				     std::ios::cur (from the current position of the get pointer.)


	-------------------------------
	General procedure:
	-------------------------------
	1. Instantiate a file stream object that will suite the needs of the program
	   with the name of the file as the parameter.
	
	2. Validate if the file was correctly opened.

	3. Use the extraction (>>) or insertion (<<) operators to input/ouput data to the file, respectively.
	
	4. Close the file explicitly using fstream_object.close() or the program will close the file
	   when the stream object goes out of scope.
