#ifndef DICTIONARY_H
#define DICTIONARY_H


#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;



class Dictionary {
public:
	//Default Constructor
	
	//opens file and assign all words into 
	Dictionary(char *filename);
	//Destructor
	
	// return a random word (without repeated letters)
	string BringValidWord();
	// check if word is in Dictionary
	bool IsWordValid(string str);
private:
	// test if n. word has only unique letters
	bool TestLegalSecretWord(string str);
	vector<string> secrets;
	set<string> words;

};






























#endif 

