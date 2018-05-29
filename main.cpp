#include <iostream>
#include "Board.h"

int main() {
    Board  board(3);
  //  board="XO.O.X.XO";
    cout<<"enter your board:";
      cin >> board;
  //  Board board1(4);
   // string fn=board1.draw(600);
    cout<<board<<endl;
    string filename = board.draw(600);

    cout << filename << endl;


    return 0;
}