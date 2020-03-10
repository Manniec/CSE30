#include <iostream>
#include <string>
#include <myLib.h>

int main(){
	std::string word = "UCMERCED";
	std::vector<char> letters = {'X', 'Y'};

	int x = countPossibleSubstrings(word, letters);
	return 0;
}
