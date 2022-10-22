#ifndef WORDS_H
#define WORDS_H

#include <iostream>
#include <set>
#include <vector>
#include <string>


using namespace std;


class Words {
public:
	Words(); //Default Constructor




	// public interface to play game of Words
	//it may call from main() using followings;
	//main(){
	//Words W;
	//W.playgame(W);
	//}
	void playgame(Words &, Dictionary);
private:
	int countofMatchLetters(string, string);
	int countofTruePlaceLetters(string, string);
	int numguesses;
	bool cheated;
	string secret;
};


























#endif