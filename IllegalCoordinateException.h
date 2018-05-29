#pragma once
#include <iostream>
#include <string>
#include "coordinate.h"
using namespace std;

class IllegalCoordinateException{
private:
  coordinate c;
public:
//Constractor
    IllegalCoordinateException (coordinate newc);

    string theCoordinate()const;
};
