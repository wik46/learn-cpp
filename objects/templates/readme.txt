Author: Lodewyk Jansen van Resnburg.
Date: December 3, 2020.
Description: 
	How to use the directory:
		1. Start of with the intro1.cpp.
		2. Take a look at the different templated array classes in intro2.cpp
		3. Take a look at 1d_array.cpp
	Directory to study templates in C++.
		- Things to remember with templates.
		* Function template instance get instantiated into function template
		  instances.
		* If you do not use the templated function/class is does not exist.		
		   That is, it is as if you did not define the function/class.
		   This is why you can define a class template in a normal way with a 
		   class definition in the header file and the implementation inside
		   a .cpp file. The file where the function is defined needs to know
		   If there is a program that want to used the function template.
		* Example: 
			template <typename T>
			void print(T val){
				std::cout << val << std::endl;
			}
			- If you calle print(5), print("name"), and print(4.3f) the
			  compiler will create 3 different instances of print. It is as if
			  you defined 3 different print functions, each taking in the particular
			  type and outputting it to the console.
		
	What a template does: (Function and Class templates)
		Every time you use a template, you need to specify to the template
		function/class with what types do you want to use it. Most of the	
		time with functions, the compiler will implicitly determine
		the type of function to create based on the types passed into the
		argument or return types.
		With template classes, we need to specify the data types
		that the classes need. Example, tak std::map< T1, T2 >.
		When creating this associative contianer, we need to specify 1.) the type
		of the key, and 2.) the type of the mapped value. 		
	
	I: Argument for templates:
		* Reduces code maintenance.
		* Reduces code duplication.
	I: Argument against templates:
		* Error message extremely difficult to debug.
		* Compile time increases because the compiler needs to create
		  the needed class and function template instances.
		* Non supported on old compilers.

	Best practices:
		1. Because templates can take in any type, (user defined in particular)
		   you want to use const T&, to prevent unecessary copying.
		2. Define the class definition and implementation inside a .hpp
		   (.hpp is a headerfile combined with an implementation file)
		   where you want to use the class.
	
	
		
