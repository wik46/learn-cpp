/*
 * Filename: operator_overl.cpp
 * Author: Wikus
 * Date: November 1, 2020
 * Description: This is a summary of the different ways to overload operators. 
 * ***************************************************************************/
#include <iostream>


// ======================================================================================
// Operator Overloading: Learncpp 9.1 - 9.6
// ======================================================================================

// Note:
// 1. You cannot overload the operator '.', '::', and ':?'.
// 2. You cannot change the number of parameters used by the function

// Ways to overload operators:
// a. Member function,
// b. friend function, and
// c. normal function.

// List of operator overloads.
// 1. Mathematical operators: +, -, *, and /.
// 2. 
// 3. Overloaded I/O operators: << and >>.
// 4. Comparison operators: ==, !=, >, =>, <, and <=.
// 5. 
// 6.
// 7.
// 8. The subscript operator: []
class Vec3d{
	// This class will be used to demonstrate operator overloading.
	float m_x;
	float m_y;
	float m_z;
public:
	// This will be the constructor that creates a vector with the 
	// given components.
	Vec3d(float x, float y, float z): m_x{x}, m_y{y}, m_z{z}
	{}
	// The copy constructor.
	Vec3d(const Vec3d& vec)
	: m_x{vec.get_x()}, m_y{vec.get_y()}, m_z{vec.get_z()}
	{}
	// The overloaded '+' operator.
	// Member function overload (type 2).
	Vec3d& operator+(const Vec3d&);
	// Pre-increment. (no dummy variable.)
	Vec3d& operator++();
	// Post-increment. (dummy variable.)
	// Note that we are returning a local copy.
	// This method is not that great as the pre-increment
	// because we need to make a local copy to get the value.
	Vec3d operator++(int);
	// This is the overloaded '*' operator.
	// It does not make sense to multiply two vectors.
	// This will be used to do scalar multiplacation.
	Vec3d& operator*(float);	
	// This is the overloaded comparison operator.
	bool operator==(const Vec3d&) const;

	// The overloaded '<<' operator.
	friend std::ostream& operator<<(std::ostream&, const Vec3d&);
	// The oveloaded '>>' operator.
	// Note that it is not a const Vec3d& becuase I want to change the value
	// at Vec3d afterwards.
	friend std::istream& operator>>(std::istream&, Vec3d&); 
	// Accessors.
	float get_x() const;
	float get_y() const;
	float get_z() const;
	// Non-const version.
	float get_x();
	float get_y();
	float get_z();

};

/* ***************************************************************************************
 * Function name: operator+().
 * Description: This function is oveloaded as a member function.
 * 		This is a binary operator.
 * **************************************************************************************/

Vec3d& Vec3d::operator+(const Vec3d& vec3){
	// Vector additions is component wise.
	this->m_x += vec3.get_x();
	this->m_y += vec3.get_y();
	this->m_z += vec3.get_z();
	// Return the Vec3d instance.
	return *this;
}
/* ***************************************************************************************
 * Function name: operator+().
 * Description: This function is oveloaded as a normal function.
 * 		This is a binary operator.
 * **************************************************************************************/
Vec3d operator+(const Vec3d& l, const Vec3d& r){
	float x = l.get_x() + r.get_x();
	float y = l.get_y() + r.get_y();
	float z = l.get_z() + r.get_z();
	// Note that I am returning by values.
	// You cannot return a reference to an object that was made in the local
	// scope of the function becuase the memory will be freed when the function goes
	// out of scope.
	return Vec3d(x,y,x);
}
/* ***************************************************************************************
 * Function name: operator++().
 * Description: This function is oveloaded as a member function.
 * Version: Pre-increment.
 * **************************************************************************************/
// This function will increment each component.
Vec3d& Vec3d::operator++(){
	++this->m_x;
	++this->m_y;
	++this->m_z;
	// Returns a referenc to the object.
	return *this;
}

/* ***************************************************************************************
 * Function name: operator++().
 * Description: This function is oveloaded as a member function.
 * Version: Post-increment.
 * Note: In order to distinguish between the pre and post increment operator,
 * 	 we pass in a dummy variable as the paramter.
 * **************************************************************************************/
Vec3d Vec3d::operator++(int){
	// This is not as effiecient as pre-increment.
	// Shallow copy is okay becuase my vector does not contain any dynamic memory.
	Vec3d temp(*this);
	// This is where the actual instance is incremented.
	// Note that I used the pre-increment operator that is already defined above.
	++(*this);
	// Return the local copy because I need the value before the increment.
	temp;
}

/* ***************************************************************************************
 * Function name: operator*().
 * Description: This function is oveloaded as a member function.
 * 		This is a binary operator.
 * 		This operator overload will be used when I want to multiply my vector
 * 		with some scalar. The result will produce a vector.
 * **************************************************************************************/
Vec3d& Vec3d::operator*(float scalar){
	// Scalar multiplaction performed on the vector.
	this->m_x *= scalar;
	this->m_y *= scalar;
	this->m_z *= scalar;
	// The result is the new vector.
	return *this;
}
/* ***************************************************************************************
 * Function name: operator==().
 * Description: This function is oveloaded as a member function.
 * 		This is a binary operator.
 * 		This operator overload will be used when I want to multiply my vector
 * 		with some scalar. The result will produce a vector.
 * **************************************************************************************/
bool Vec3d::operator==(const Vec3d& vector) const{
	return ((this->m_x == vector.get_x())
	&& (this->m_y == vector.get_y())
	&& (this->m_z == vector.get_z()));
}

/* ***************************************************************************************
 * Function name: operator<<().
 * Description: This function is oveloaded as a friend function.
 * 		This is a binary operator.
 * 		Remember to return a reference to the ostream instance that you used.
 * 		This is a friend fuction of Vec3d. Therefore it has access to its privte
 * 		members but is not a member function.
 * 		Friend function do not have access to the classes 'this' pointer.
 * **************************************************************************************/
std::ostream& operator<<(std::ostream& stream_out, const Vec3d& vec3d){
	stream_out << "< " << vec3d.get_x() 
	<< ", " << vec3d.get_y()
	<< ", "<< vec3d.get_z() << " >";
	// Always remember to return the instance of the ostream object.
	return stream_out;
}
/* ***************************************************************************************
 * Function name: operator>>().
 * Description: This function is oveloaded as a friend function.
 * 		This is a binary operator.
 * 		Remember to return a reference to the istream instance that you used.
 * 		This is a friend fuction of Vec3d. Therefore it has access to its privte
 * 		members but is not a member function.
 * 		Friend function do not have access to the classes 'this' pointer.
 * **************************************************************************************/
std::istream& operator>>(std::istream& stream_in, Vec3d& vec){
	// This function assumes that the user will enter floats.
	std::cout << "x component: ";
	stream_in >> vec.m_x;
	std::cout << "y component: ";
	stream_in >> vec.m_y;
	std::cout << "z component: ";
	stream_in >> vec.m_z;
	return stream_in;
}
/* ***************************************************************************************
 * Function name: get_x().
 * Description: Accessor function and a mutator (getter and a setter.) 
 * **************************************************************************************/
float Vec3d::get_x() const{
	return this->m_x;
}
/* ***************************************************************************************
 * Function name: get_y().
 * Description: Accessor function and a mutator (getter and a setter.) 
 * **************************************************************************************/
float Vec3d::get_y() const{
	return this->m_y;
}
/* ***************************************************************************************
 * Function name: get_z().
 * Description: Accessor function and a mutator (getter and a setter.) 
 * **************************************************************************************/
float Vec3d::get_z() const{
	return this->m_z;
}
/* ***************************************************************************************
 * Function name: get_x().
 * Description: Accessor function and a mutator (getter and a setter.) 
 * **************************************************************************************/
float Vec3d::get_x(){
	return this->m_x;
}
/* ***************************************************************************************
 * Function name: get_y().
 * Description: Accessor function and a mutator (getter and a setter.) 
 * **************************************************************************************/
float Vec3d::get_y(){
	return this->m_y;
}
/* ***************************************************************************************
 * Function name: get_z().
 * Description: Accessor function and a mutator (getter and a setter.) 
 * **************************************************************************************/
float Vec3d::get_z(){
	return this->m_z;
}




int main(){
	Vec3d v1(0,0,0);
	Vec3d v2(0,0,10);
	Vec3d v3(1,2,3);
	// Example1 :Use of the oveloaded '+' operator.
	// This will add v2 to v1 and store the new vector in v1.
	// NB! v1 is changed.
	v1 + v2;
	std::cout << "1.) Vector addition: "<< v1 << std::endl << std::endl;
	// Example 2: Scalar multiplication.
	float scalar = 4.6;
	v1 = v1 * scalar;
	std::cout << "2.) Scalar multiplication: "<< v1 << std::endl << std::endl;
	// Example 3: Vector addition with a normal function.
	// Note that this will change the value of v2.
	std::cout << "3.) Vector addition: " << v2 + v3 << std::endl; 
	// Example 4: The overloaded >> operator.
	std::cin >> v1;
	std::cout << std::endl << "4.) Your input: " << v1 << std::endl;
	// Example 5: Using the comparison operator.
	std::cout << std::endl << "5.) Comparison between: " << v1 << " and "
	<< v3 << std::endl;
	if(v1 == v3){
		std::cout << "Equal." << std::endl;
	}else{
		std::cout << "Not equal." << std::endl;
	}
	// Example 6: Pre/Post - increment.
	Vec3d v4(0,0,0);
	Vec3d v5(0,0,0);
	std::cout << std::endl;
	std::cout << "6.) Pre/Post - increment." << std::endl
	<< "Before: "<< std::endl;
	std::cout << "v4: " << v4 <<std::endl
	<< "v5: " << v5 << std::endl;
	// Showing the pre/post working.
	std::cout << "v4 - pre: " << ++v4<<std::endl
	<< "v5 - post: " << v5++ << std::endl;
	
	std::cout << std::endl << "Summary of all the vectors used." << std::endl;	
	std::cout << "v1: " << v1 << std::endl
	<< "v2: " << v2 << std::endl
	<< "v3: " << v3 << std::endl;
	return 0;
}
