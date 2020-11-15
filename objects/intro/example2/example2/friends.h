// Filename: friends.h
// Author: Wikus.
// Date: October 30, 2020.
// Description: This will be a file to store all the friend functions
// 		used by the point class. The main purpose of this file
// 		is to practise using friend functions.
//

#ifndef FRIENDS_H
#define FRIENDS_H
#include "Point.h"
#include <iostream>

// This function outputs the point's x, y, and z-values.
std::ostream& operator<<(std::ostream&, const Point& );

#endif
