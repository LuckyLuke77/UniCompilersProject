#include "functions.h"
#include <iostream>
using namespace std;

string GenerateString(string phrase) {
    int numberOfWords;
    int randomIndex;
    cout << phrase << endl;
    for (int i = 0; i < 100; i++) {
        numberOfWords = WordCount(phrase); // Calculates the number of non-final words inside the phrase given
        randomIndex = words[Random(1, numberOfWords) - 1] + 1; // Find the index of a random non-final word
        phrase = ReplaceSymbol(phrase, randomIndex); // Replace the non-final word
        cout << phrase << endl;
    }
    return "";
}

int main() {
    string initPhrase = "<Z>";
    GenerateString(initPhrase);
}