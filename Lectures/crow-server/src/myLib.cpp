#include <myLib.h>

std::string sayHello(){
    return "Hello World";
}

std::string echoWord(std::string word){
    return word;
}

ucm::json getSuperBowlScore(){
        ucm::json data;      
          
        data["home_team"] = "New England Patriots";
        data["home_score"] = 13;
        data["away_team"] = "Los Angeles Rams";
        data["away_score"] = 3;

        return data;
}

ucm::json quadratic(float a, float b, float c){
    ucm::json result;

    result["x1"] = (-b + sqrt(b*b - 4 * a * c))/(2*a);
    result["x2"] = (-b - sqrt(b*b - 4 * a * c))/(2*a);

    return result;
}

ucm::json countMostFreqLetter(std::string input){
    // ABACADAE
    // Create a hash table for each character that appears in the string, indicating how many times it appears
    // We will store this in a hash table:

    // A : 4
    // B : 1
    // C : 1
    // D : 1

    // Then we will take the maximum

    std::unordered_map<char, int> occurTable;

    for (int i = 0; i < input.size(); i++){
        input[i] = toupper(input[i]);
        // Check if current char appears in table
        auto check = occurTable.find(input[i]);
        
        // If it is found, increase value by 1
        // If not found, insert key with value 1
        if (check != occurTable.end()){
            // We found it
            occurTable[input[i]]++;
        }
        else {
            // We did not find it
            occurTable.insert({input[i], 1});
        }
    }


    // Now find the maximum value and its corresponding key

    char K;
    int max = 0;

    for (auto itr : occurTable){
        char k = itr.first;
        int v = itr.second;

        if (v >= max){
            max = v;
            K = k;
        }
    }

    // Return the result as a JSON

    ucm::json result;

    result["character"] = K;
    result["frequency"] = max;

    return result;
}
