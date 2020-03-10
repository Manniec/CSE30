#include <myLib.h>
#include <unordered_map>
#include <iostream>
#include <algorithm>

int add (int x, int y){
	return x+y;
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

    // G O O G L E

    std::unordered_map<char, int> needed;

    for (int i = 0; i < word.size(); i++){
        auto check = needed.find(word[i]);
        if (check == needed.end()){
            // Did not find it
            needed.insert({word[i], 1});
        }
        else {
            // We found it
            needed[word[i]]++;
        }
    }


    for (auto element: needed){
        std::cout << element.first << ": " << element.second << std::endl;
    }



    int gCount = 0;
    int oCount = 0;
    int lCount = 0;
    int eCount = 0;


    /* Hash tables
        ht = {
            
            'O' : 2,
            'L' : 1,
            'E' : 1,
            'G' : 2
        }
        
        ht['O'] => 2
        ht['L'] => 1

        ht2 = {
            'john' : 21,
            'mary' : 12,
            'tom' : 18,
            'pam' : 16
        }

        ht2['john'] => 21


        Array: arr = [0:5,1:7,2:3,3:1,4:8]

        arr[1] => 7 (7 is the 1th element)


    */

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
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /*

    // We first check what letters we need to make the word
    // as well as how many of each letter

    std::unordered_map<char, int> needed;

    for (int i = 0; i < word.size(); i++){
        auto check = needed.find(word[i]);
        if (check == needed.end()){
            needed.insert({word[i], 1});
        }
        else{
            needed[word[i]]++;
        }
        
    }

    // Then we look at how many of each letter we have 

    std::unordered_map<char, int> have;

    for (int i = 0; i < letters.size(); i++){
        auto check = needed.find(letters[i]);
        if (check != needed.end()){
            auto contains = have.find(letters[i]);
            if (contains == have.end()){
                have.insert({letters[i], 1});
            }
            else{
                have[letters[i]]++;
            }
        }
    }

    // Do we have all the letters we need?

    for (auto element : needed){
        auto check = have.find(element.first);
        if (check == have.end()){
            return 0;
        }
    }

    // Divide the amount we have by the amount we need, for each letter

    for (auto element : have){
        have[element.first] /= needed[element.first];
    }

    // Get the minimum 

    auto result = std::min_element(have.begin(), have.end(), [](std::pair<char, int> lhs, std::pair<char, int> rhs){
        return lhs.second < rhs.second;
    });

    return result->second;

    
}
*/
