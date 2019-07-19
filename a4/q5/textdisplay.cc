#include "textdisplay.h"
#include "subject.h"

TextDisplay::TextDisplay(int n) : gridSize{n} {
    for (int i = 0; i < gridSize; i++) {
        std::vector<char> v;
        for (int j = 0; j < gridSize; j++) {
            v.emplace_back('-');
        }
        theDisplay.emplace_back(v);
    }
    theDisplay[gridSize / 2][gridSize / 2] = 'B';
    theDisplay[gridSize / 2 - 1][gridSize / 2 - 1] = 'B';
    theDisplay[gridSize / 2][gridSize / 2 - 1] = 'W';
    theDisplay[gridSize / 2 - 1][gridSize / 2] = 'W';
}

void TextDisplay::notify(Subject<Info, State> &whoNotified){
    char c = (whoNotified.getInfo().colour == Colour::Black) ? 'B' : 'W';
    theDisplay[whoNotified.getInfo().row][whoNotified.getInfo().col] = c;
}

std::ostream & operator<<(std::ostream &out, const TextDisplay &td){
    for(int i = 0; i < td.gridSize; i++) {
        for(int j = 0; j < td.gridSize; j++)
            out << td.theDisplay[i][j]; 
        out << std::endl;
    }
    return out;
}





