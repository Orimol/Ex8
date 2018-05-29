#include "coordinate.h"

coordinate::coordinate (size_t newi, size_t newj):i(newi),j(newj){}


size_t coordinate::getI()const{
  return i;
}

size_t coordinate::getJ()const{
  return j;
}

coordinate& coordinate::operator = (coordinate newc){
  i = newc.getI();
  j = newc.getJ();
  return *this;
}
