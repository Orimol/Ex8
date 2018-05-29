#include "DosentFitException.h"

DosentFitException::DosentFitException (string s):str(s){}

string DosentFitException::thestring()const{
    string ans=str;
    return ans;
}
