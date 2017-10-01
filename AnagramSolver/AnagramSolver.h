
#ifndef __ANAGRAMSOLVER_H__
#define __ANAGRAMSOLVER_H__

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "LetterInventory.h"

using namespace std;

class AnagramSolver {

public:
   AnagramSolver(const vector<string>& dictList);
   ~AnagramSolver();
   
   void print(const string& s, int max);
   
private:
   vector<string> dictionary;
   unordered_map<string, LetterInventory*> dictionaryMap;
   
   void exploreAnagrams(LetterInventory* current, vector<string>& wordChoices, const vector<string>& availableWords, unsigned int max);
};

#endif
