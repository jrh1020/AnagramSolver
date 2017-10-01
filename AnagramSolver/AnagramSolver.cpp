

#include "AnagramSolver.h"

AnagramSolver::AnagramSolver(const vector<string>& dictList) : dictionary(dictList) {
   
   for (string word : dictList) {
      LetterInventory* l = new LetterInventory(word);
      dictionaryMap[word] = l;
   }
}

AnagramSolver::~AnagramSolver() {
   
   for (auto it : dictionaryMap) {
      delete it.second;
   }
}

void AnagramSolver::print(const string& s, int max) {
   
   if (max < 0) {
      throw invalid_argument("AnagramSolver::print(const string&,int): max is negative");
   }
   
   LetterInventory* wordInventory = new LetterInventory(s);
   vector<string> availableWords;
   for (string word : dictionary) {
      LetterInventory* result = *wordInventory - *dictionaryMap[word];
      if (result != nullptr) {
         availableWords.push_back(word);
      }
      delete result;
   }
   
   vector<string> wordChoices;
   exploreAnagrams(wordInventory, wordChoices, availableWords, max);
   delete wordInventory;
}

void AnagramSolver::exploreAnagrams(LetterInventory* current, vector<string>& wordChoices,
                                    const vector<string>& availableWords, unsigned int max) {
   
   if (current->isEmpty()) {
      auto it = wordChoices.begin();
      cout << "[" << *it++;
      for (; it != wordChoices.end(); it++) {
         cout << ", " << *it;
      }
      cout << "]" << endl;
      
   } else if (max == 0 || wordChoices.size() != max) {
      for (string word : availableWords) {
         LetterInventory* tryInventory = *current - *dictionaryMap[word];
         if (tryInventory != nullptr) {
            wordChoices.push_back(word);
            exploreAnagrams(tryInventory, wordChoices, availableWords, max);
            wordChoices.pop_back();
         }
         
         delete tryInventory;
      }
   }
}
