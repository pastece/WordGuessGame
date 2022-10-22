#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "dictionary.h"
#include "words.h"

using namespace std;

int main()
{
	char letter, myfile[30]="Words.txt";

	Dictionary my_dictionary(myfile);
	Words my_game;


	while (true) {
		my_game.playgame(my_game, my_dictionary);
		cout << "Bir daha oynamak icin 'e' oyunu sonlandirmak icin 'h' tusuna bas: ";
		cin >> letter;
		if (letter == 'h') break;
		if (letter == 'e') continue;
		else break;
	}

	system("pause");
	return 0;
}