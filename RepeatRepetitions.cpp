/***********************************
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
  
  FILE* file = fopen("text", "r");
  
  if (file == NULL) {
    return 0;
  }
  
  int letterFrequency = 1, alphabetIndex = 0;
  
  while (!feof(file)) {
    fscanf(file, "%s", textLine);
    
    for (int letterIndex = 0; letterIndex < strlen(textLine); ++letterIndex) {
      if ((textLine[letterIndex] >= 65 && textLine[letterIndex] <= 90)
      || (textLine[letterIndex] >= 97 && textLine[letterIndex] <= 122)) {
        
        bool letterRepeat = 0;
        int letterRepeatedIndex;
        
        if (letterIndex != strlen(textLine) &&
           (textLine[letterIndex] == textLine[letterIndex + 1] || 
        abs(textLine[letterIndex] - textLine[letterIndex+ 1]) == 32)) {
          ++countTwoLetterComb;
        }
        
        for (int repeatIndex = 0; repeatIndex < alphabetIndex; ++repeatIndex) {
          if (fileAlphabet[repeatIndex] == textLine[letterIndex] || 
          abs(fileAlphabet[repeatIndex] - textLine[letterIndex]) == 32) {
            letterRepeat = 1;
            letterRepeatedIndex = repeatIndex;
          }
        }
        
        if (letterRepeat == 0) {
          if (!(textLine[letterIndex] >= 65 && textLine[letterIndex] <= 90)) {
            textLine[letterIndex] -= 32;
          }
          
          fileAlphabet[alphabetIndex] = textLine[letterIndex];
          letterFrequencyArray[alphabetIndex] = letterFrequency;
          
          ++alphabetIndex;
        } else {
          letterFrequencyArray[letterRepeatedIndex] += letterFrequency; 
        }
      }
    }
  }
  
  for (int outIndex = 0; outIndex < alphabetIndex; ++outIndex) {
    if (letterFrequencyArray[outIndex] > 1) {
      cout << fileAlphabet[outIndex] << " — " << letterFrequencyArray[outIndex] << endl;
    }
  }
  
  cout << "Number of two-letter combinations: " << countTwoLetterComb << endl;
}
