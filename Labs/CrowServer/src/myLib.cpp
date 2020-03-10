#include <myLib.h>

std::string sayHello(){
    return "Hello World";
}

std::string echoWord(std::string word){
    std::string reversed;
    for (int i = word.size(); i >= 0; i--){
        reversed = reversed + word[i];
    }
    return reversed;
}

ucm::json getSuperBowlScore(){
        ucm::json data;      
          
        data["home_team"] = "New England Patriots";
        data["home_score"] = 13;
        data["away_team"] = "Los Angeles Rams";
        data["away_score"] = 3;

        return data;
}

ucm::json toUpperLower(std::string input){
    ucm::json words;
    
    std::string u = input;
    std::string l = input;

    transform(input.begin(), input.end(), u.begin(), ::toupper);
    transform(input.begin(), input.end(), l.begin(), ::tolower);

    words["upper"] = u;
    words["lower"] = l;
    
    return words;
}

