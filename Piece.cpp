#include "Piece.h"

Piece::Piece (char c):value(c){}
Piece::Piece ():value('.'){}

char Piece::getValue()const{
  return value;
}

std::ostream& operator<<(std::ostream& o, Piece const& p){
  return o<<p.getValue();
}

Piece& Piece::operator = (char c){
  if(c!='X'&&c!='O'&&c!='.') throw IllegalCharException(c);
  value = c;
  return *this;
}

bool Piece::operator == (char c)const{
  if (value==c) return true;
  else return false;
}
