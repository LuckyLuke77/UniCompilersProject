#include "tools.h"
#include <iostream>
using namespace std;

const int SIZE = 100;
int words[SIZE];
// Count the number of non-final words contained withing the given phrase (by counting the number of "<" found)
// Also create an Array "words" that contains the indexes of the aforementioned non-final words inside the phrase
int WordCount(string phrase) {
    int chars = 0;
    int i = 0;
    while(i < phrase.length()) {
        if (phrase[i] == '<') { 
            //cout << i << endl;
            words[chars] = i;
            chars++;
            i += 3;
        } else {
            i++;
        }
    }
    return chars;
}

string ReplaceSymbol(string phrase, int i) {
    //cout << phrase[i] << endl;
    if (phrase[i] == 'Z') {
        phrase = growList(phrase, 2, i+1);
        phrase[i - 1] = '(';
        phrase[i] = '<';
        phrase[i + 1] = 'K';
        phrase[i + 2] = '>';
        phrase[i + 3] = ')';
    } else if (phrase[i] == 'K') {
        phrase = growList(phrase, 3, i+1);
        phrase[i - 1] = '<';
        phrase[i] = 'G';
        phrase[i + 1] = '>';
        phrase[i + 2] = '<';
        phrase[i + 3] = 'M';
        phrase[i + 4] = '>';
    } else if (phrase[i] == 'G') {
        int flipCoin = Random(0, 1);
        if(flipCoin == 1) {
            phrase[i - 1] = 'v';
            phrase[i] = ' ';
            phrase[i + 1] = ' ';
            phrase = reduceList(phrase, 2, i+2);
        } else {
            phrase[i - 1] = '<';
            phrase[i] = 'Z';
            phrase[i + 1] = '>';
        }
    } else if (phrase[i] == 'M') {
        int dice = Random(0, 2);
        if(dice == 0) {
            phrase = growList(phrase, 1, i+1);
            phrase[i - 1] = '-';
            phrase[i] = '<';
            phrase[i + 1] = 'K';
            phrase[i + 2] = '>';
        } else if (dice == 1) {
            phrase = growList(phrase, 1, i+1);
            phrase[i - 1] = '+';
            phrase[i] = '<';
            phrase[i + 1] = 'K';
            phrase[i + 2] = '>';
        } else {
            phrase = reduceList(phrase, 3, i+2);
        }
    }
    return phrase;
}
