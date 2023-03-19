
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "AnagramSolver.h"

using namespace std;

int main(int nArgs, char** czArgs) {
   
   cout << "Welcome to the cse143 anagram solver." << endl;
   cout << endl;
   
   string filename;
   cout << "What is the name of the dictionary file? ";
   cin >> filename;
   cin.get();
   
   ifstream input(filename);
   if (!input) {
      return 1;
   }
   
   vector<string> dictionary;
   while (!input.eof()) {
      string line;
      getline(input, line);
      dictionary.push_back(line);
   }
   input.close();
   
   // Removes the blank line at the end of the file
   dictionary.pop_back();
   
   AnagramSolver solver(dictionary);
   string phrase;
   bool done = false;
   while (!done) {
      cout << endl;
      cout << "phrase to scramble (return to quit)? ";
      getline(cin, phrase);
      
      if (phrase.length() == 0) {
         done = true;
      } else {
         cout << "Max words to include (0 for no max)? ";
         int max = 0;
         cin >> max;
         cin.get();
         clock_t t = clock();
         solver.print(phrase, max);
         t = clock() - t;
         cout << ((float)t)/CLOCKS_PER_SEC;
      }
   }
   
   return 0;
}
