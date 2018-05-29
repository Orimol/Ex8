#pragma once
#include <iostream>
#include <string>
using namespace std;

class DosentFitException{
private:
    string str;
public:
//Constractor
     DosentFitException (string s);

    string thestring()const;
};
