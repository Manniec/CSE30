#include <igloo/igloo.h>

#include <myLib.h>

using namespace igloo;

Context(HelloFunction) {

	Spec(TheOnlyTestPossible) {
		Assert::That(sayHello(), Equals("Hello World"));
	}
};



Context(CountFreqFunction){
	Spec(SimpleTest){

		std::string input = "ABACADAE";
		ucm::json result;
		result["character"] = 'A';
        result["frequency"] = 4;
		
		Assert::That(countMostFreqLetter(input), Equals(result));
	}
	Spec(FailTest){
		std::string input = "GoogleG";
		ucm::json result;
		result["character"] = "G";
		result["frequency"] = "3";

		Assert::That(countMostFreqLetter(input), Equals(result));
	}
};


Context(QuadraticFunction){
	Spec(OnlyPossibleTest){
		ucm::json result;
		result["x1"] = 1;
        result["x2"] = -1;
		
		Assert::That(quadratic(1,0,-1), Equals(result));
	}
};

Context(EchoFunction) {

	Spec(EchoHello) {
		Assert::That(echoWord("hello"), Equals("hello"));
	}

	Spec(EchoWorld) {
		Assert::That(echoWord("world"), Equals("world"));
	}
};



Context(SuperBowlFunction){
	Spec(OnlyPossibleTest){
		ucm::json score;
		score["home_team"] = "New England Patriots";
        score["home_score"] = 13;
        score["away_team"] = "Los Angeles Rams";
        score["away_score"] = 3;
		
		Assert::That(getSuperBowlScore(),Equals(score));
	}
};


int main() {
	// Run all the tests defined above
	return TestRunner::RunAllTests();
}
