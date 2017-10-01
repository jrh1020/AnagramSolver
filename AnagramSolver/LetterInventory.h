
#ifndef __LETTERINVENTORY_H__
#define __LETTERINVENTORY_H__

#include <iostream>
#include <string>
#include <locale>
#include <memory>

//using namespace std;
using std::string;
using std::ostream;
using std::invalid_argument;

class LetterInventory {
   
public:
   
   LetterInventory(const string& data);
   ~LetterInventory();
   
   int get(char letter);
   void set(char letter, int value);
   int size();
   bool isEmpty();
   
   LetterInventory* operator+(const LetterInventory& other); 
   LetterInventory* operator-(const LetterInventory& other);
   
   friend ostream& operator<<(ostream& output, const LetterInventory& li);

private:
   
   static const char LOW_ALPHA = 'a';
   static const char HIGH_ALPHA = 'z';
   static const int ALPHABET_SIZE = (int)(HIGH_ALPHA - LOW_ALPHA + 1);
   
   int* _letterCount;
   int _size;
   
   int getIndex(char c);
};

#endif
