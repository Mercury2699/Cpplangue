#include <iostream>
#include <string>
#include "grid.h"
#include "state.h"
using namespace std;

// Do not remove any code; do not add code other than where indicated.

int main(int argc, char *argv[]){
  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd;
  Grid g;
  Colour lastplayed = Colour::White;
  
  try{
    while (true){
      cin >> cmd;
      if (cmd == "new"){
        int n;
        cin >> n;
        g.init(n);
        lastplayed = Colour::White;
      }
      else if (cmd == "play"){
        int r = 0, c = 0;
        cin >> r >> c;
        if (r < 0 || c < 0) continue;
        try {
          if(lastplayed == Colour::White){
            g.setPiece(r,c,Colour::Black);
            lastplayed = Colour::Black;
          } else if(lastplayed == Colour::Black){
            g.setPiece(r,c,Colour::White);
            lastplayed = Colour::White;
          }
        } catch (std::logic_error e) {
          continue;
        }
        if (g.isFull()) {
          if (g.whoWon() == Colour::Black) {
            cout << "Black wins!" << std::endl;
          } else if (g.whoWon() == Colour::White) {
            cout << "White wins!" << std::endl;
          } else {
            cout << "Tie!" << std::endl;
          }
          break;
        }
      }
    }
  }
  catch (ios::failure &){}  // Any I/O failure quits
}






