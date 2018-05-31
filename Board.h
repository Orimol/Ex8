#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include "Piece.h"
#include "coordinate.h"
#include "IllegalCoordinateException.h"
#include "IllegalCharException.h"
#include <fstream>
#include "DosentFitException.h"
#include <sys/stat.h>
using namespace std;




class Board{
private:
  size_t size;
  Piece **board;


public:
//Constractor and Destractor
    Board (size_t newsize);
    Board (Board &b);
    Board();
    ~Board();

//Methods
Board& init(size_t bsize);

Board& operator = (string s);

Board& operator = (Board newb);

Board& operator = (char c);

friend std::ostream& operator<<(std::ostream& o, Board const& b);

Piece& operator [] (const coordinate& c);

string draw (size_t n);

friend std::istream& operator >> (std::istream& in, Board& b);



}
;
