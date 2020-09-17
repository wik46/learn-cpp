/*
	Written by Justin Goins as an in-class demo
	Note that we will learn better approaches in future lectures.
*/
#include <iostream>
#include "course.h"

using namespace std;

int Course::next_crn = 1234;

// destructor
Course::~Course() {
	//cout << "Destructor called!" << endl;
	delete [] roster;
}

// default constructor
Course::Course() {
	//cout << "Default constructor called." << endl;
	enrollment_cap = DEFAULT_ENROLLMENT_CAP;
	name = "Default name";
	roster = new string[enrollment_cap];
	crn = next_crn++;
}

// alternate constructor
// this one allows the user to specify a maximum enrollment
Course::Course(int e_cap) {
	//cout << "Alternate constructor callled." << endl;
	enrollment_cap = e_cap;
	roster = new string[e_cap];
	crn = next_crn++;
}

// alternate constructor
// this one specifies the maximum enrollment
// and the name
Course::Course(int e_cap, string new_name) {
	//cout << "Alternate constructor callled." << endl;
	name = new_name;
	enrollment_cap = e_cap;
	roster = new string[enrollment_cap];
	crn = next_crn++;
}

void Course::set_name(string new_name) {
	name = new_name;
}

string Course::get_name() const {
	return name;
}

int Course::get_enrollment() const {
	return current_enrollment;
}

void Course::enroll_student(string student_name) {
	if (current_enrollment == enrollment_cap) {
		cout << "Course is full. Could not enroll '" << student_name << "'." << endl;
		return;
	}

	roster[current_enrollment] = student_name;
	current_enrollment++;
}

void Course::display_roster() {
	cout << "Course Roster for " << name << ":" << endl;
	cout << "\tCRN: " << crn << endl;
	for (int i = 0; i < current_enrollment; i++) {
		cout << "\t" << roster[i] << endl;
	}
}
