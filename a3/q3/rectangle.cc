#include "rectangle.h"

Rectangle::Rectangle(Point upperLeft, int height, int width, Colour colour) 
	:upperleft{upperLeft} , hi{height}, wd{width}, color{colour} {}

void Rectangle::translate(int x, int y) {
	upperleft = Point(x,y);
}

Point Rectangle::lowerRight() const {
	Point p = upperleft;
	p.a += wd;
	p.b += hi;
	return p;
}

void Rectangle::scale(float heightFactor, float widthFactor){
	int newHeight = hi * heightFactor;
	int newWidth = wd * widthFactor;
	hi = newHeight > 0 ? newHeight : 0;
	wd = newWidth > 0 ? newWidth : 0;
}

void Rectangle::change(Colour newColour) {
	color = newColour;
}

Colour Rectangle::colour() const {
	return color;
}

Point Rectangle::point() const {
	return upperleft;
}

int Rectangle::width() const {
	return wd;
}

int Rectangle::height() const {
	return hi;
}

static Colour translateColour(char c) {
	switch(c) {
		case 'r' : return Colour::Red;
		case 'g' : return Colour::Green;
		case 'b' : return Colour::Blue;
		case 'y' : return Colour::Yellow;
		case 'o' : return Colour::Orange;
		case 'a' : return Colour::Black;
		case 'w' : return Colour::White;
	}
	return Colour::Red;
}

std::ostream& operator<<(std::ostream & out, Colour color) {
	switch(color) {
		case Colour::Red : return out << "Red";
		case Colour::Green : return out << "Green";
		case Colour::Blue : return out << "Blue";
		case Colour::Yellow : return out << "Yellow";
		case Colour::Orange : return out << "Orange";
		case Colour::Black : return out << "Black";
		case Colour::White : return out << "White";
	}
	return out << "Red";
}

std::istream & operator>>(std::istream & in, Rectangle & rectangle) {
	char c;
	Colour color;
	int x, y, hei, wid;
	in >> c >> x >> y >> hei >> wid;
	color = translateColour(c);
	rectangle = Rectangle(Point(x,y),hei,wid,color);
	return in;
}

std::ostream & operator<<(std::ostream & out, const Rectangle & rectangle) {
	return out << "[" << rectangle.color << " " << rectangle.upperleft << " " 
		<< rectangle.hi << "x" << rectangle.wd << "]";
}






