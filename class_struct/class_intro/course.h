/*
	Written by Justin Goins as an in-class demo
*/
#ifndef COURSE_H
#define COURSE_H

#include <iostream>
using namespace std;

#define DEFAULT_ENROLLMENT_CAP 100

class Course {
public:
	~Course(); //destructor
	Course(); //default constructor
	Course(int); //alternate constructor
	Course(int, string); //alternate constructor
	void set_name(string);
	string get_name() const;
	int get_enrollment() const;
	void enroll_student(string);
	void display_roster();

private:
	static int next_crn;
	int crn;
	string name;
	int current_enrollment = 0;
	int enrollment_cap;
	string *roster;
};

#endif
