***********************************
* Автор: Машин Егор               *
* Дата:  20.12.2022               * 
* Тема:  Частота повторений       *
***********************************/ 

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
    
  int letterFrequencyArray[26], countTwoLetterComb = 0;
  
  char textLine[100], fileAlphabet[26];
  
  setlocale(LC_ALL, "ru");
  
  FILE* file = fopen("text", "r");
  
  if (file == NULL) {
    return 0;
  }
  
  int letterFrequency = 1, indexAlphabet = 0;
  
  while (!feof(file)) {
    fscanf(file, "%s", textLine);
    
    for (int indexLetter = 0; indexLetter < strlen(textLine); ++indexLetter) {
      if ((textLine[indexLetter] >= 65 && textLine[indexLetter] <= 90)
      || (textLine[indexLetter] >= 97 && textLine[indexLetter] <= 122)) {
        
        bool repeatLetter = 0;
        int indexLetterRepeated;
        
        if (indexLetter != strlen(textLine) &&
           (textLine[indexLetter] == textLine[indexLetter + 1] || 
        abs(textLine[indexLetter] - textLine[indexLetter + 1]) == 32)) {
          ++countTwoLetterComb;
        }
        
        for (int indexRepeat = 0; indexRepeat < indexAlphabet; ++indexRepeat) {
          if (fileAlphabet[indexRepeat] == textLine[indexLetter] || 
          abs(fileAlphabet[indexRepeat] - textLine[indexLetter]) == 32) {
            repeatLetter = 1;
            indexLetterRepeated = indexRepeat;
          }
        }
        
        if (repeatLetter == 0) {
          if (!(textLine[indexLetter] >= 65 && textLine[indexLetter] <= 90)) {
            textLine[indexLetter] -= 32;
          }
          
          fileAlphabet[indexAlphabet] = textLine[indexLetter];
          letterFrequencyArray[indexAlphabet] = letterFrequency;
          
          ++indexAlphabet;
        } else {
          letterFrequencyArray[indexLetterRepeated] += letterFrequency; 
        }
      }
    }
  }
  for (int indexOut = 0; indexOut < indexAlphabet; ++indexOut) {
    if (letterFrequencyArray[indexOut] > 1) {
      cout << fileAlphabet[indexOut] << " — " << letterFrequencyArray[indexOut] << endl;
    }
  }
  cout << "Number of two-letter combinations: " << countTwoLetterComb << endl;
}
