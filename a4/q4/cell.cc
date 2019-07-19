#include "cell.h"

Cell::Cell(size_t r, size_t c) : r{r}, c{c} {}

void Cell::setPiece(Colour colour){
    if(this->colour != Colour::NoColour) return;
    this->colour = colour;
    setState({StateType::NewPiece, colour, Direction::NW});
    notifyObservers();
    setState({StateType::NewPiece, colour, Direction::N});
    notifyObservers();
    setState({StateType::NewPiece, colour, Direction::NE});
    notifyObservers();
    setState({StateType::NewPiece, colour, Direction::W});
    notifyObservers();
    setState({StateType::NewPiece, colour, Direction::E});
    notifyObservers();
    setState({StateType::NewPiece, colour, Direction::SW});
    notifyObservers();
    setState({StateType::NewPiece, colour, Direction::S});
    notifyObservers();
    setState({StateType::NewPiece, colour, Direction::SE});
    notifyObservers();
}

void Cell::toggle(){
    if (colour == Colour::Black){
        colour = Colour::White;
    } else if (colour == Colour::White){
        colour = Colour::Black;
    } else {
        return;
    }
}

bool Cell::isLined(Subject<Info, State> &whoFrom){
    size_t rother = whoFrom.getInfo().row;
    size_t cother = whoFrom.getInfo().col;
    size_t rthis = this->getInfo().row;
    size_t cthis = this->getInfo().col;
    Direction dirother = whoFrom.getState().direction;
    if (rother == rthis - 1 && cother == cthis - 1) return dirother == Direction::NW;
    if (cother == cthis && rother == rthis - 1) return dirother == Direction::N;
    if (cother == cthis + 1 && rother == rthis - 1) return dirother == Direction::NE;
    if (cother == cthis - 1 && rother == rthis) return dirother == Direction::W;
    if (cother == cthis + 1 && rother == rthis) return dirother == Direction::E;
    if (cother == cthis - 1 && rother == rthis + 1) return dirother == Direction::SW;
    if (cother == cthis && rother == rthis + 1) return dirother == Direction::S;
    if (cother == cthis + 1 && rother == rthis + 1) return dirother == Direction::SE;
    return false;
}

Direction Cell::revDirect(Direction d){
    if (d == Direction::NW) return Direction::SE;
    if (d == Direction::N) return Direction::S;
    if (d == Direction::NE) return Direction::SW;
    if (d == Direction::W) return Direction::E;
    if (d == Direction::E) return Direction::W;
    if (d == Direction::SW) return Direction::NE;
    if (d == Direction::S) return Direction::N;
    if (d == Direction::SE) return Direction::NW;
    return Direction::NW; //impossible fallback
}

void Cell::notify(Subject<Info, State> &whoFrom){
    Direction dirother = whoFrom.getState().direction;
    if (this->colour != Colour::NoColour){ // only react if is set
        if (isLined(whoFrom)) { // only react if is in line
            if (whoFrom.getState().type == StateType::NewPiece) { // propulse as Relay
                if (whoFrom.getInfo().colour != this->colour){
                    setState({StateType::Relay, whoFrom.getInfo().colour, dirother});
                    notifyObservers();
                }
            } else if (whoFrom.getState().type == StateType::Relay) { // single direction
                if(whoFrom.getInfo().colour == this->colour) { // keep passing
                    setState({StateType::Relay, whoFrom.getInfo().colour, dirother});
                } else if (whoFrom.getInfo().colour != this->colour) { // reverse it if same color
                    setState({StateType::Reply, this->colour, revDirect(dirother)});
                }
                notifyObservers();
            } else if (whoFrom.getState().type == StateType::Reply) { // reverse direction
                if(whoFrom.getInfo().colour != this->colour) {// flip myself and propulse 
                    this->toggle();
                    setState({StateType::Reply, whoFrom.getInfo().colour, dirother});
                    notifyObservers();
                }
            }
        }
    }
}

Info Cell::getInfo() const{
    return Info{r,c,colour};
}





