#include "grid.h" 
#include <stdexcept>
#include "textdisplay.h"

Grid::~Grid(){
    delete td;
    delete ob;
}

void Grid::setObserver(Observer<Info, State> *ob){
}

bool Grid::isFull() const{
    for (size_t i = 0; i < gridSize; i++){
        for (size_t j = 0; j < gridSize; j++) {
            if (theGrid[i][j].getInfo().colour == Colour::NoColour)
                return false;
        }
    }
    return true;
}

Colour Grid::whoWon() const{
    int wcount = 0, bcount = 0;
    for (size_t i = 0; i < gridSize; i++){
        for (size_t j = 0; j < gridSize; j++) {
            if (theGrid[i][j].getInfo().colour == Colour::Black) {
                bcount++;
            } else if (theGrid[i][j].getInfo().colour == Colour::White){
                wcount++;
            }
        }
    }
    if (bcount == wcount) return Colour::NoColour;
    return bcount > wcount ? Colour::Black : Colour::White;
}

void Grid::init(size_t n){
    if (n % 2 || n < 3) return;
    if (gridSize) theGrid.clear();
    gridSize = n;
    delete td;
    td = new TextDisplay(n);
    for (size_t i = 0; i < gridSize; i++) {
        std::vector<Cell> v;
        for (size_t j = 0; j < gridSize; j++) {
            v.emplace_back(Cell(i,j));
        }
        theGrid.emplace_back(v);
    }
    theGrid[gridSize / 2][gridSize / 2].setPiece(Colour::Black);
    theGrid[gridSize / 2 - 1][gridSize / 2 - 1].setPiece(Colour::Black);
    theGrid[gridSize / 2][gridSize / 2 - 1].setPiece(Colour::White);
    theGrid[gridSize / 2 - 1][gridSize / 2].setPiece(Colour::White);
    for(size_t i = 0; i < gridSize; i++){
        for(size_t j = 0; j < gridSize; j++){
            if (i > 0 && j > 0) theGrid[i][j].attach(&theGrid[i-1][j-1]);
            if (i > 0) theGrid[i][j].attach(&theGrid[i-1][j]);
            if (i > 0 && j < gridSize - 1) theGrid[i][j].attach(&theGrid[i-1][j+1]);
            if (j > 0) theGrid[i][j].attach(&theGrid[i][j-1]);
            if (j < gridSize - 1) theGrid[i][j].attach(&theGrid[i][j+1]);
            if (i < gridSize - 1 && j > 0) theGrid[i][j].attach(&theGrid[i+1][j-1]);
            if (i < gridSize - 1) theGrid[i][j].attach(&theGrid[i+1][j]);
            if (i < gridSize - 1 && j < gridSize - 1) theGrid[i][j].attach(&theGrid[i+1][j+1]);
            theGrid[i][j].attach(td);
        }
    }
    std::cout << *td;
}

void Grid::setPiece(size_t r, size_t c, Colour colour){
    if(gridSize == 0) throw std::logic_error("not inited");
    if(theGrid[r][c].getInfo().colour != Colour::NoColour) throw std::logic_error("already played");
    if(r >= gridSize || c >= gridSize || r < 0 || c < 0) throw std::logic_error("invalid r/c");
    theGrid[r][c].setPiece(colour);
    td->notify(theGrid[r][c]);
    std::cout << *td;
}

void Grid::toggle(size_t r, size_t c){
    theGrid[r][c].toggle();
    td->notify(theGrid[r][c]);
}

std::ostream & operator<<(std::ostream &out, const Grid &g){
    return out << *(g.td);
}












