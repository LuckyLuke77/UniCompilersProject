#include "functions.h"
#include <iostream>
using namespace std;

const int NUM_OF_LOOPS = 150; // Maximum number of replacements the program will do before finishing
void GenerateString(string phrase) {
    int numberOfWords;
    int randomIndex;
    int i = 1;
    do {
        cout << i << ". " << phrase << endl; // Print the phrase
        numberOfWords = WordCount(phrase); // Calculates the number of non-final words inside the phrase given
        randomIndex = words[Random(1, numberOfWords) - 1]; // Find the index of a random non-final word
        phrase = ReplaceSymbol(phrase, randomIndex); // Replace the non-final word
        i++;
    } while (i <= NUM_OF_LOOPS && numberOfWords != 0);
}

int main() {
    string initPhrase = "<Z>"; // Initialize the phrase with the starting word
    GenerateString(initPhrase); // Beging the generating proccess
}