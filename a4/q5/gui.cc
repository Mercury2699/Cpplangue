#include "gui.h"

GraphicsDisplay::GraphicsDisplay(size_t size) : gridSize{size} {
    int unit = static_cast<int> (500 / gridSize);
    w.fillRectangle(0,0,500,500,Xwindow::Blue);
    w.fillRectangle(250,250,unit,unit);
    w.fillRectangle(250 - unit, 250 - unit, unit, unit);
    w.fillRectangle(250, 250 - unit, unit, unit, Xwindow::White);
    w.fillRectangle(250 - unit, 250, unit, unit, Xwindow::White);
}

void GraphicsDisplay::notify(Subject<Info, State> &whoFrom){
    int cother = static_cast<int>(whoFrom.getInfo().row);
    int rother = static_cast<int>(whoFrom.getInfo().col);
    int unit = static_cast<int>(500 / gridSize);
    Colour color = whoFrom.getInfo().colour;
    if(color == Colour::Black) 
    w.fillRectangle(rother * unit, cother * unit, unit, unit);
    if(color == Colour::White) 
    w.fillRectangle(rother * unit, cother * unit, unit, unit, Xwindow::White);
}




