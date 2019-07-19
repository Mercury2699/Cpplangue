#include "canvas.h"

Canvas::Canvas(){
    listCapacity = 5;
    rectangleCount = 0;
    edge = Point();
    listRectangle = new Rectangle*[listCapacity];
}

Canvas::~Canvas(){
    this->empty();
    delete [] listRectangle;
}
//copy ctor
Canvas::Canvas(const Canvas & other)
    :listCapacity{other.listCapacity}, rectangleCount{other.rectangleCount},
    edge{other.edge} {
        listRectangle = new Rectangle*[listCapacity];
        if (other.listRectangle){
            for (int i = 0; i < rectangleCount; i++) {
                Rectangle * cpy = new Rectangle{other.listRectangle[i]->upperleft, 
                other.listRectangle[i]->hi, 
                other.listRectangle[i]->wd, 
                other.listRectangle[i]->color};
                listRectangle[i] = cpy;
            }
        }
    }
//move ctor
Canvas::Canvas(Canvas && other) 
    :listCapacity{other.listCapacity}, rectangleCount{other.rectangleCount}, edge{other.edge}, listRectangle{other.listRectangle} {
    other.listRectangle = nullptr;
    other.rectangleCount = 0;
}
//copy assignment
Canvas & Canvas::operator=(const Canvas & other){
    listCapacity = other.listCapacity;
    rectangleCount = other.rectangleCount;
    edge = other.edge;
    listRectangle = new Rectangle*[listCapacity];
    if (other.listRectangle){
        for (int i = 0; i < rectangleCount; i++) {
            Rectangle * cpy = new Rectangle{other.listRectangle[i]->upperleft, 
            other.listRectangle[i]->hi, 
            other.listRectangle[i]->wd, 
            other.listRectangle[i]->color};
            listRectangle[i] = cpy;
        }
    }
    return *this;
}
//move assignment
Canvas & Canvas::operator=(Canvas && other){
    listCapacity = other.listCapacity;
    rectangleCount = other.rectangleCount;
    edge = other.edge;
    listRectangle = other.listRectangle;
    other.listRectangle = nullptr;
    other.rectangleCount = 0;
    return *this;
}

void Canvas::add(const Rectangle & rectangle){
    if (rectangleCount >= listCapacity) {
        Rectangle ** newArr = new Rectangle*[listCapacity*2];
        for (int i = 0; i < listCapacity; i++) {
            newArr[i] = listRectangle[i];
        }
        listCapacity *= 2;
        delete[] listRectangle;
        listRectangle = newArr;
        newArr = nullptr;
    }
    Rectangle * add = new Rectangle{rectangle};
    listRectangle[rectangleCount++] = add;
    edge = maxPoint(edge, rectangle.lowerRight());
}

int Canvas::numRectangles() const{
    return rectangleCount;
}

int Canvas::width() const {
    return edge.a;
}

int Canvas::height() const {
    return edge.b;
}

Rectangle Canvas::get(int rectangleId) const {
    return *(listRectangle[rectangleId]);
}

void Canvas::translate(int rectangleId, int x, int y) {
    listRectangle[rectangleId]->upperleft = Point{x > 0 ? x : 0 , y > 0 ? y : 0};
    edge = Point();
    for(int i = 0; i < rectangleCount; i++) {
        edge = maxPoint(edge, listRectangle[i]->lowerRight());
    }
}

void Canvas::scale(int rectangleId, float heightFactor, float widthFactor) {
    listRectangle[rectangleId]->scale(heightFactor, widthFactor);
    edge = Point();
    for(int i = 0; i < rectangleCount; i++) {
        edge = maxPoint(edge, listRectangle[i]->lowerRight());
    }
}

void Canvas::change(int rectangleId, Colour newColour) {
    listRectangle[rectangleId]->color = newColour;
    edge = Point();
    for(int i = 0; i < rectangleCount; i++) {
        edge = maxPoint(edge, listRectangle[i]->lowerRight());
    }
}

void Canvas::remove(int rectangleId) {
    delete listRectangle[rectangleId];
    for (int i = rectangleId; i < rectangleCount-1; i++) {
        listRectangle[i] = listRectangle[i+1];
    }
    rectangleCount--;
    edge = Point();
    for(int i = 0; i < rectangleCount; i++) {
        edge = maxPoint(edge, listRectangle[i]->lowerRight());
    }
}

void Canvas::empty() {
    for (int i = 0; i < rectangleCount; i++) {
        delete listRectangle[i];
    }
    rectangleCount = 0;
    edge = Point();
}

std::ostream & operator<<(std::ostream & out, const Canvas & canvas){
    out << "Dimensions: " << canvas.edge.y() << "x" << canvas.edge.x() << std::endl;
    out << "Number of rectangles: " << canvas.numRectangles() << std::endl;
    if (canvas.listRectangle) {
        for (int i = 0; i < canvas.numRectangles(); i++) {
            out << "\t" << *(canvas.listRectangle[i]) << std::endl;
        }
    }
    return out;
}

