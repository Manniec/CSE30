#include <myLib.h>
#include <algorithm>

std::vector<std::string> readWordsFile(std::string filename){ //creates vector of uppercase strings from txt file
    std::ifstream file(filename);
    std::string str; 

    std::vector<std::string> words;

    while (std::getline(file, str)){
        words.push_back(boost::to_upper_copy(str));
        
    }

    return words;
}

std::unordered_map<std::string, bool> hashdict; //hashtable of words from english alphabet 


ucm::json checkWord(std::string word){

    ucm::json x;

    x["word"] = word;
    x["valid"] = false;

    auto got = hashdict.find(word);
    if(got != hashdict.end()){ //check if word is a key in hashdict
        //We found it
        x["valid"] = hashdict[word];
        hashdict[word] = false; //limit so word can be used only once
    }
    
    return x; //Json object with "word" key and "valid" value
}


 ucm::json getList(){
    std::vector <std::string> dictionary = readWordsFile("misc/english.txt"); //make vector of words from txt file
    //for each word in dictionary
     for(int i = 0; i < dictionary.size(); i++){
         if(dictionary[i].size() <= 9){ //if word is over 9 letters
             hashdict.insert({dictionary[i], true}); //add it as key in hashtable
         }
    }

    ucm::json result;

    /*
    srand(time(NULL));
    //vowels
    int vowels[6] = {65,69,73,79,85,89};
    for(int i = 0; i < 3; i++){
         int indexV;
         indexV = rand() % 5;
         result.push_back(vowels[indexV]);
    }

    //consonants 
    int c;
    int j;
   
   int cons[20] = {66,67,68,70,71,72,74,75,76,77,78,80,81,82,83,84,86,87,88,90};

   for(int i = 0; i < 6; i++){
       int indexC;
       indexC = rand() % 19;
       result.push_back(cons[indexC]);
   }
   */

    

    
    //pick random word
    int wordlen = 10;
    int index;
    std::string baseWord;
    while(wordlen > 9){
        index = rand() % dictionary.size();
        wordlen = dictionary[index].size();
    }
    baseWord = dictionary[index];

    //if word has less than 9 characters 
    if 
    
    

     /*
     result.push_back('H');
     result.push_back('E');
     result.push_back('L');
     result.push_back('L');
     result.push_back('O');
     result.push_back('F');
     result.push_back('G');
     result.push_back('H');
     result.push_back('I');
     */

     return result;
 }

std::vector<std::string> powerset(std::string str){
    if (str.size() == 0){ //if null string
        std::vector<std::string> result;
        result.push_back("");

        return result; //returns vector w one element (empty string) -> [""]
    }
    else{ //else
        char head = str[0]; //head = character first letter string
        std::string tail; 
        tail = str.substr (1,std::string::npos); //set tail= end of string (exempt first character)

        std::vector<std::string> res = powerset(tail); // res = powerset of rest of letters (exempt first) (recursion)
        std::vector<std::string> ans = res; //ans = powerset of rest of letters (exempt first)

        for (auto element : res){ //for each element in powerset of rest of letters
            std::string temp = element; //set equal to temp
            temp.insert(temp.begin(), head); //inserts first letter infront of letter
            ans.push_back(temp); //adds temp to powerset
        }

        return ans;
    }
}

void permute(std::string a, int l, int r, std::vector<std::string>& results) {

    if (l == r)  { // if integers are the same return string a
        results.push_back(a);
    }  
    else {  
        for (int i = l; i <= r; i++) {    // from int l to int r 
            char temp = a[l]; // set temp == the lth letter of string a
            a[l] = a[i]; // replace the lth letter of string a to the ith letter between between l and r
            a[i] = temp; // set the ith letter of the string to the new temp
             
            permute(a, l+1, r, results);   // permute the rest of the string (recursive)

            temp = a[l]; 
            a[l] = a[i];
            a[i] = temp;  
        }  
    }  
}  


