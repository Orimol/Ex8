#pragma once
#include <iostream>
#include <string>
using namespace std;

class IllegalCharException{
private:
  char c;
public:
//Constractor
    IllegalCharException (char newc);

    char theChar()const;
};
