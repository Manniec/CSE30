#include <myLib.h>

int add (int x, int y){
	return x + y;
}

int getMin(int a, int b, int c, int d){
    int first = a;
    if (b < a){
        first = b;
    }

    int second = c;
    if (d < c){
        second = d;
    }

    if (first <= second){
        return first;
    }
    else{
        return second;
    }
}

int countPossibleSubstrings(std::string word, std::vector<char> letters){
    int gCount = 0;
    int oCount = 0;
    int lCount = 0;
    int eCount = 0;

    for (int i = 0; i < letters.size(); i++){
        if (toupper(letters[i]) == 'G'){
            gCount++;
        }
        else if (toupper(letters[i]) == 'O'){
            oCount++;
        }
        else if (toupper(letters[i]) == 'L'){
            lCount++;
        }
        else if (toupper(letters[i] == 'E')){
            eCount++;
        }
    }

    gCount = gCount / 2;
    oCount /= 2;

    return getMin(gCount, oCount, lCount, eCount);
}
