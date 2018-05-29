#pragma once
#include <iostream>
#include <string>
using namespace std;

class coordinate{
private:
  size_t i,j;

public:
//Constractor
    coordinate (size_t i, size_t j);

    size_t getI()const;
    size_t getJ()const;

    coordinate& operator = (coordinate newc);
};
