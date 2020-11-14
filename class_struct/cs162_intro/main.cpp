/*
	Written by Justin Goins as an in-class demo
*/
#include <iostream>
#include "course.h"

using namespace std;

// Note that this function accepts a reference to a course
void print_entire_course(Course &c) {
	cout << c.get_name() << endl;
	c.display_roster();
}

/*
  Illustrate how to design a Course class
*/
int main() {

	cout << "welcome!" << endl;
	Course c1(100, "CS123"); // declare a course with a maximum capacity of 3 students and a name of CS123
	cout << "Created a new course. Retrieved name: " << c1.get_name() << endl;

	c1.enroll_student("Sandra McPherson");
	c1.enroll_student("Adam Brown");
	c1.enroll_student("Sally Brown");
	c1.enroll_student("Late John");
	cout << "Number of students enrolled: " << c1.get_enrollment() << endl;
	c1.display_roster();

//	print_entire_course(c2);
	return 0;
}
