#include <iostream>
using namespace std;

int i;
string growList(string list, int growLen, int stopIndex) { 
    for (i = 0; i < growLen; i ++) {                    // Increase the size of the list
        list += ' ';
    }               
    for (i = list.length(); i >= stopIndex; i --) {     // Move everything to the right
        list[i] = list[i - growLen];
    }
    return list;
}
                                                                    // EXAMPLE:
string reduceList(string list, int reduceLen, int startIndex) {     // (<G><M>) 
    for (i = startIndex; i < list.length(); i++) {                  //     ^- startIndex (4)
        list[i - reduceLen] = list[i];                              // (v<M>)>) - replace <G> with v
    }                                                               
    list.erase(list.length() - reduceLen, list.length());           // (v<M>) - cleanup extra symbols
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
