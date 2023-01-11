#include <iostream>
using namespace std;

string growList(string list, int growLen, int stopIndex) {
    //for (int i = list.length(); i > stopIndex; i--) {
        int i;
        for (i = 0; i < growLen; i ++) {list += " ";}
        int listLen = list.length() - growLen;
        for (i = list.length(); i >= stopIndex; i --) {
            list[i] = list[i - growLen];
        }
        return list;
    //}
}

string reduceList(string list, int reduceLen, int startIndex) {
    int i;
    for (i = startIndex; i < list.length(); i++) {
        list[i - reduceLen] = list[i];
    }
    for (i = list.length(); i >= list.length() - reduceLen; i--) {
        list[i] = ' ';
    }
    return list;
}

// "Random()" code source: https://stackoverflow.com/a/7560171
int Random(int min, int max) //range : [min, max]
{
   static bool first = true;
   if (first) 
   {  
      srand( time(NULL) ); //seeding for the first time only!
      first = false;
   }
   return min + rand() % (( max + 1 ) - min);
}
