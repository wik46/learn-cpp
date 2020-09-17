 /**************************************************
 *Program Filename: class_ex1.cpp
 *Author: Wikus
 *Date: 18 July 2020
 *Description: Learning how to use th create a log function to print types of errors
 *Input
 *Output
 **************************************************/


#include <iostream> //Remember all that the #inlcude statement does is copy and paiste

//
class Log_func{

public:
	//These variables are used to determine the warning I want to set my function
	

	// This will print all the message types
	//The user can use these variables to set the loglevel instead of typing in 0,1, or 2.
	int LogLevelInfo(2);
	//This will only print warning and error messages
	int LogLevelWarn = 1;
	//This will only print error messages
	int LogLevelError = 0;
//Private means that I can only use the variable inside this class scope. I can not access the variable outside the class scope
//like a public variable. Remember that a class is set to private by default and a stuct is set to public by default.
private:
	//Note the m int the front, this is a naming convention to help me remember that this variable can only be accesed within the scope of this class
	int m_LogLevel;
public:
	/*setLogLevel is used to determine what messages I want to print*/

	void setLogLevel(int level){
		m_LogLevel = level;
	} 
	
	//Log level set to LogLevelInfo will print all three types of messages
	void info(const char* message){
		if(m_LogLevel >= LogLevelInfo){
		std::cout << "[INFO]: " << message << std::endl;
		}
	}
	//Log level set to LogLevelWarn will only print warning and error messages
	void warn(const char* message){
		if(m_LogLevel >= LogLevelWarn){
		std::cout << "[WARNING]: " << message << std::endl;
		}
	}
	//Log level set to LogLevelError will only print error messages	
	void error(const char* message){
		if(m_LogLevel >= LogLevelError){
		std::cout << "[ERROR]: " << message << std::endl;
		}
	}

};

int main(){

	Log_func log;
	log.setLogLevel(LogLevelWarn);
	log.info("This is a message");
	log.warn("This is a message");
	log.error("This is a message");
	return 0;
}
