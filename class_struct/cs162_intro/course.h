/*
	Written by Justin Goins as an in-class demo
*/

// This is a header guard
#ifndef COURSE_H  
#define COURSE_H

// #ifndef COURSE_H checks if COURSE_H was already defined. If it was then this header file will not be included twice.
// You cannot define a function/struct with the same name and parameters twice. You will get an error.
// If COURSE_H	 was not defined it will run the code and define COURSE_H so that the file only gets run once.

#include <iostream>

#define DEFAULT_ENROLLMENT_CAP 100

class Course {
public:
	~Course(); //destructor
	Course(); //default constructor
	Course(int); //alternate constructor
	Course(int, std::string); //alternate constructor
	void set_name(std::string);
	std::string get_name() const;
	int get_enrollment() const;
	void enroll_student(std::string);
	void display_roster();

private:
	static int next_crn;
	int crn;
	std::string name;
	int current_enrollment = 0;
	int enrollment_cap;
	std::string *roster;
};

#endif
