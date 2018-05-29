#include "IllegalCharException.h"

IllegalCharException::IllegalCharException (char newc):c(newc){}

 char IllegalCharException::theChar()const{
   char ans=c;
   return ans;
 }
