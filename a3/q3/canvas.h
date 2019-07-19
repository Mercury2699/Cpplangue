#ifndef _CANVAS_H
#define _CANVAS_H
#include "rectangle.h"

// The upper left-hand corner of a Canvas is at (0,0). X-coordinates increase
// towards the right (there is no negative value). Y-coordinates increase
// downwards (there is no negative value). Canvases hold Rectangles.
struct Canvas {

    /* Add your variables and functions HERE */
	int listCapacity, rectangleCount;
	Point edge; // height and width of the canvas
	Rectangle ** listRectangle;

	// Creates an initially empty Canvas, which has its height == width == 0.
	Canvas(); // ctor
	Canvas(const Canvas & other); // copy ctor
	Canvas(Canvas && other); // move ctor: copy other and destroy it
	~Canvas(); // dtor
	Canvas & operator=(const Canvas & other); // copy assignment 
	Canvas & operator=(Canvas && other); // move assignment 

	// Adds the given Rectangle after already existing rectangles. The
	// dimensions of the Canvas "stretch" to fit the Rectangle, if necessary,
	// depending upon where the Rectangle's upper-left-hand corner is defined
	// to be and its dimensions. 
	void add(const Rectangle & rectangle); 

	// Returns the number of rectangles in the Canvas.
	int numRectangles() const; 

	// Returns the width of the Canvas.
	int width() const; 

	// Returns the height of the Canvas.
	int height() const; 

	// Returns the rectangle indexed, where 0 <= rectangleId < numRectangles().
	Rectangle get(int rectangleId) const;

	// Moves the Rectangle's Point to the specified coordinate. Requires 
	// 0 <= rectangleId < numRectangles(). The resulting Point's coordinates
	// must stay >= 0.
	void translate(int rectangleId, int x = 0, int y = 0);

	// Scales the Rectangle's dimensions by the specified amounts. The resulting
	// dimensions must be integers > 0. Requires 0 <= rectangleId < 
	// numRectangles().
	void scale(int rectangleId, float heightFactor = 1.0, float widthFactor = 1.0);

	// Changes the Rectangle's colour to the new colour.
	void change(int rectangleId, Colour newColour);

	// Removes Rectangle with specified index. Requires 0 <= rectangleId < 
	// numRectangles(). For all Rectangles with index j > rectangleId, their
	// new index becomes j -= 1.
	void remove(int rectangleId);

	// Remove all rectangles from the specified canvas
	void empty();
};

// You may add an input operator if you wish.

// Outputs the Canvas. Format is:
// Dimensions: heightxwidth
// Number of rectangles: N
// \t[Rectangle_0]
// ...
// \t[Rectangle_N-1]
// where '\t' is a tab character.
std::ostream & operator<<(std::ostream & out, const Canvas & canvas);

#endif





