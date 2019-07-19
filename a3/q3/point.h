#ifndef _POINT_H
#define _POINT_H
#include <iostream>

// A Point has an x- and a y-coordinate. The coordinates must be >= 0/
struct Point {

    // Add your variables and functions HERE.
	int a, b;

	

	// The x- and y-coordinates of the Point must be >= 0.
	Point(int x = 0, int y = 0);

	// Returns the x-coordinate.
	int x() const;

	// Returns the y-coordinate.
	int y() const;

	// Returns a new Point{this->x+other.x, this->y+other.y}.
	Point operator+(const Point & other) const;
};

// You may add an input operator if you wish.

// maxPoint returns a point with the larger coords of the two points
	Point maxPoint(Point &, Point);

// Outputs the Point to the specified output stream in the format: "(x,y)".
std::ostream & operator<<(std::ostream & out, const Point & point);

#endif




