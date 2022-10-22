#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <fstream>
#include <time.h>
#include "dictionary.h"
#include "words.h"

const int MAX_CHAR = 256;
using namespace std;





Dictionary::Dictionary(char *filename)
{

	fstream dataFile;
	string tmp;
	bool check;

	dataFile.open(filename, fstream::in);
	if (!dataFile)
	{
		cout << "File open error!" << endl;
		exit(0);
	}
	else
	{
		cout << "Oyun baslatiliyor!\n" << endl;

		dataFile >> tmp;
		while (!dataFile.eof())
		{
			check = TestLegalSecretWord(tmp);

			if (check) secrets.push_back(tmp);

			words.insert(tmp);
			dataFile >> tmp;
		}


	}	

	dataFile.close();
}

bool Dictionary::TestLegalSecretWord(string str)
{
	bool chars[MAX_CHAR] = { 0 };

	for (int i = 0; i < str.length(); i++) {
		if (chars[int(str[i])] == true)
			return false;

		chars[int(str[i])] = true;
	}
	return true;
}

string Dictionary::BringValidWord()
{
	int x, y;
	string validword;
	srand(time(0));

	x = secrets.size();
	y = rand() % x;

	validword = secrets[y];

	return validword;
}


bool Dictionary::IsWordValid(string str)
{
	int size1, size2;
	string buffer;

	size1 = words.size();
	size2 = str.size();

	if (size2 != 5) return false;

	for (set<string>::iterator it = words.begin(); it != words.end(); ++it)
	{
		buffer = *it;
		if (buffer == str) return true;
		
	}

	return false;
}



Words::Words()
{
	cheated = false;
	numguesses = 0;
}

void Words::playgame(Words &, Dictionary my_dictionary)
{

	int match, place;
	string guess;
	char myfile[30] = "words.txt";
	bool  check, flag = 1;

	secret = my_dictionary.BringValidWord();
	

	cout << "Bilbakalim Oyununa Hosgeldiniz\n";
	cout << "5 harften olusan bir kelime tuttum.\n";
	

	while (flag)
	{
		cout << "Tahmininiz nedir: ";
		cin >> guess;		

		if (guess == "xxxxx") {
			cout << "Ipucu: Gizli Kelime: " << secret << endl << endl;
			numguesses++;
			cheated = true;
			continue;
		}

		check = my_dictionary.IsWordValid(guess);
			

		if (check == false) cout << "Bu kelime sozlukte yok\n\n";			


		else if (check == true) {
			numguesses++;

			if (guess == secret) {
				flag = 0;
				if (cheated == false) cout << "Bildiniz! " << numguesses << " tahminde dogru sonuca ulastiniz!\n";
				if (cheated == true) cout << "Bildiniz! " << numguesses << " tahminde ipucu kullanarak dogru sonuca ulastiniz!\n";
			}

			else {
				match = countofMatchLetters(secret, guess);
				place = countofTruePlaceLetters(secret, guess);

				cout << "Eslesen harf sayisi: " << match << endl;
				cout << "Eslesen harflerin dogru konumu: " << place << endl << endl;
			}
		}
	}

	cheated = false;
	numguesses = 0;



}

int Words::countofMatchLetters(string str1, string str2)
{

	int count = 0;

	for (string::size_type it1 = 0; it1 < str1.size(); ++it1) {

		for (string::size_type it2 = 0; it2 < str2.size(); ++it2) {

			if (str1[it1] == str2[it2]) {
				count++;
				it2 = str2.size();
			}
		}

	}

	return count;


}

int Words::countofTruePlaceLetters(string str1, string str2)
{

	int count = 0;

	string::size_type it2 = 0;

	for (string::size_type it1 = 0; it1 < str1.size(); ++it1) {

		if (str1[it1] == str2[it2]) count++;
		it2++;

	}

	return count;


}