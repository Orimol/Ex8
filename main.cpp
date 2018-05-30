#include <iostream>
#include "Board.h"

int main() {
    Board board;

    //board="XO.O.X.XO";
   // cout<<"enter your board:\n";
       cin >> board;
    //  Board board1(4);
   // string fn=board1.draw(600);
    cout<<board<<endl;
    string filename = board.draw(600);
    cout<<"check"<<endl;
    cout << filename << endl;


    return 0;
}