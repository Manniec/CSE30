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
		std::vector<char> letters = {'A', 'B', 'C'};
		Assert::That(countPossibleSubstrings(word, letters), Equals(0));
	}

	Spec(OneOfEach) {
		std::vector<char> letters = {'G', 'O', 'L', 'E'};
		Assert::That(countPossibleSubstrings(word, letters), Equals(0));
	}

	Spec(Once) {
		std::vector<char> letters = {'G', 'O', 'O', 'G', 'L', 'E'};
		Assert::That(countPossibleSubstrings(word, letters), Equals(1));
	}

	Spec(Scrambbled) {
		std::vector<char> letters = {'L', 'O', 'E', 'G', 'G', 'O'};
		Assert::That(countPossibleSubstrings(word, letters), Equals(1));
	}

	Spec(Twice) {
		std::vector<char> letters = {'G', 'O', 'O', 'G', 'L', 'E', 'G', 'O', 'O', 'G', 'L', 'E'};
		Assert::That(countPossibleSubstrings(word, letters), Equals(2));
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
