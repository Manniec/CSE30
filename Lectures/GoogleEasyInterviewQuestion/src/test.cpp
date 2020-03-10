#include <igloo/igloo.h>

#include "myLib.h"

using namespace igloo;


Context(AdderFunction) {

	Spec(SimpleTest) {
		Assert::That(add(3, 5), Equals(8));
	}

	Spec(NegativeNumbers) {
		Assert::That(add(-5, -2), Equals(-7));
	} 

	Spec(PositiveAndNegative) {
		Assert::That(add(-4, 3), Equals(-1));
	}
};

Context(CountFunction) {

	std::string word = "GOOGLE";

	Spec(None) {
		std::vector<char> letters;
		letters.push_back('A');
		letters.push_back('B');
		letters.push_back('C');
		Assert::That(countPossibleSubstrings(word, letters), Equals(0));
	}

	Spec(Once) {
		std::vector<char> letters;
		letters.push_back('G');
		letters.push_back('O');
		letters.push_back('O');
		letters.push_back('G');
		letters.push_back('L');
		letters.push_back('E');
		Assert::That(countPossibleSubstrings(word, letters), Equals(1));
	}

	Spec(Scambled) {
		std::vector<char> letters;
		letters.push_back('L');
		letters.push_back('O');
		letters.push_back('E');
		letters.push_back('G');
		letters.push_back('G');
		letters.push_back('O');
		Assert::That(countPossibleSubstrings(word, letters), Equals(1));
	}
	Spec(Twice) {
		std::vector<char> letters;
		letters.push_back('G');
		letters.push_back('O');
		letters.push_back('O');
		letters.push_back('G');
		letters.push_back('L');
		letters.push_back('E');
		letters.push_back('G');
		letters.push_back('O');
		letters.push_back('O');
		letters.push_back('G');
		letters.push_back('L');
		letters.push_back('E');
		Assert::That(countPossibleSubstrings(word, letters), Equals(2));
	}
	Spec(OneMissing) {
		std::vector<char> letters;
		letters.push_back('G');
		letters.push_back('O');
		letters.push_back('O');
		letters.push_back('G');
		letters.push_back('L');
		letters.push_back('E');
		letters.push_back('G');
		letters.push_back('O');
		letters.push_back('O');
		letters.push_back('G');
		letters.push_back('L');
		letters.push_back('X');
		Assert::That(countPossibleSubstrings(word, letters), Equals(1));
	}
};

Context(MinFunction) {

	Spec(FirstIsTheAnswer) {
		Assert::That(getMin(1, 2, 3, 4), Equals(1));
	}

	Spec(secondIsTheAnswer) {
		Assert::That(getMin(2, 1, 3, 4), Equals(1));
	}

	Spec(ThirdIsTheAnswer) {
		Assert::That(getMin(3, 2, 1, 4), Equals(1));
	}

	Spec(FourthIsTheAnswer) {
		Assert::That(getMin(4, 2, 3, 1), Equals(1));
	}
};

int main() {
	// Run all the tests defined above
	return TestRunner::RunAllTests();
}
