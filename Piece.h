#pragma once
#include <iostream>
#include <string>
#include "IllegalCharException.h"
using namespace std;



class Piece{
private:
  char value;

public:

  Piece (char x);
  Piece ();

  char getValue()const;

  friend std::ostream& operator<<(std::ostream& o, Piece const& p);

  Piece& operator = (char c);

  bool operator == (char c)const;
};
