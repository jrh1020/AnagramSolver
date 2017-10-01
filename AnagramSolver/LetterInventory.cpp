
#include "LetterInventory.h"

LetterInventory::LetterInventory(const string& data) : _size(0) {
   
   _letterCount = new int[ALPHABET_SIZE]();
   
   for (char c : data) {
      if (isalpha(c)) {
         _letterCount[getIndex(c)]++;
         _size++;
      }
   }
}

LetterInventory::~LetterInventory() {
   
   delete[] _letterCount;
}

int LetterInventory::get(char letter) {
   
   if (!isalpha(letter)) {
      throw invalid_argument("LetterInventory::get(char): char is unalphabetic");
   }
   
   return _letterCount[getIndex(letter)];
}

void LetterInventory::set(char letter, int value) {
   
   if (value < 0) {
      throw invalid_argument("LetterInventory::set(char,int): value is negative");
   }
   if (!isalpha(letter)) {
      throw invalid_argument("LetterInventory::set(char,int): letter is unalphabetic");
   }
   
   _size = _size + (value - _letterCount[getIndex(letter)]);
   _letterCount[getIndex(letter)] = value;
}

int LetterInventory::size() {
   
   return _size;
}

bool LetterInventory::isEmpty() {
   
   return _size == 0;
}

LetterInventory* LetterInventory::operator+(const LetterInventory& other) {
   
   LetterInventory* tempInventory = new LetterInventory("");
   for (int i = 0; i < ALPHABET_SIZE; i++) {
      tempInventory->set(i + LOW_ALPHA, _letterCount[i] + other._letterCount[i]);
   }
   return tempInventory;
}

LetterInventory* LetterInventory::operator-(const LetterInventory& other) {
   
   LetterInventory* tempInventory = new LetterInventory("");
   for (int i = 0; i < ALPHABET_SIZE; i++) {
      int count = _letterCount[i] - other._letterCount[i];
      if (count < 0) {
         delete tempInventory;
         return nullptr;
      }
      
      tempInventory->set(i + LOW_ALPHA, count);
   }
   
   return tempInventory;
}

ostream& operator<<(ostream& output, const LetterInventory& li) {
   
   output << "[";
   for (int i = 0; i < LetterInventory::ALPHABET_SIZE; i++) {
      for (int j = 0; j < li._letterCount[i]; j++) {
         output << (char)(LetterInventory::LOW_ALPHA + i);
      }
   }
   
   output << "]";
   return output;
}

int LetterInventory::getIndex(char c) {
   
   if (!isalpha(c)) {
      throw invalid_argument("LetterInventory::getIndex(char): c is unalphabetic");
   }
   
   c = tolower(c);
   return (int)(c - LOW_ALPHA);
}

