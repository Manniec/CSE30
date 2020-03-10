#include <myLib.h>
#include <algorithm>

std::vector<std::string> readWordsFile(std::string filename){// takes file name and produce vector of uppercase strings
    std::ifstream file(filename);
    std::string str; 

    std::vector<std::string> words;

    while (std::getline(file, str)){
        words.push_back(boost::to_upper_copy(str));
        
    }

    return words;
}
std::vector <std::string> dictionary; //same has making a hashtable with integer key and string value

std::unordered_map<std::string, bool> hashmap; //store word create slot labeled with that word as its key

ucm::json checkWord(std::string word){ //check word! takes in word

    ucm::json x;

    x["word"] = word; 
    x["valid"] = false; //produces answer that word is valid. 
    //always start search by setting to false (always assume search will fail)

    //go to misc folder (dictionary full of words)
    //std::vector<std::string> dictionary = readWordsFile("/misc/english.txt");
    //if you look for readWordsFile("kldsoifdapi") it doesnt error out!, 
    //C++ has no problem reading a file that doesnt exist clearly its not a real filename. 
    //you only error out if you try to use the result 
    //you get a segmentation fault error (doesnt tell you where in the error is in the code )
    //std::cout << dictionary[0] <<std::endl; //check if file path correct immediately!!
    //this line would read from harddrive every time it runs. so move it!
    //Move to get line function

    /*
    for(int i = 0; i < dictionary.size(); i++){ //linear search
        if (word == dictionary[i]){ //go through list and compare each word
            x["vaild"] = true;
            break;
            //optionally break still runs, but break --> faster computation 
        }
    }
    */
    //how long does it take for the computer to compute the for loop? (look at resources)
    //190 milasec => takes a long time to run through. 
    //add a break -> word that starts with a is near begining so loop completed quicker
    //words that arnt in list take longer than words that are early in list by alot

    /*run time depends on input size. Most CPU intensive line of code is equality compariston 
    - best case: search for first item in list (a)
    - worse case: search for something that isnt in the list at all 
    */
    /* if you had to repeat the 200 milisecond operation many times it would take a long time.  
    Ways to make this faster:
    - cut out words that are longer than 9 letters (can't spell them anyway)
    - Hashtable can do this in one opperation instead 
    */
    
    auto got = hashmap.find(word);

    if(got != hashmap.end()){
        //We found it
        x["valid"] = true;
    }


    return x;
}

 ucm::json getList(){ 

     // lect 2 You happen to know getList is called first 
    dictionary = readWordsFile("/misc/english.txt");

    for(int i = 0; i < dictionary.size(); i++){
        hashmap.insert({dictionary[i], true}); //just ask is there a chairth item in there?
    }
     //io operations (reading from the ram) are slow, so do them only when needed

     ucm::json result;
     /*hard coded buttons
     result.push_back('A');
     result.push_back('B');
     result.push_back('C');
     result.push_back('D');
     result.push_back('E');
     result.push_back('F');
     result.push_back('G');
     result.push_back('H');
     result.push_back('I');
     */

    //you want letters to change -> random number gen
    srand(time(NULL));
    //int r = rand() % 25 + 65 //(gets random numb from 0 to 25) and adds 65
    //repeat for each button 
    for(int i = 0; i < 9; i++){ //no vowels might happen--> no words can be made!
        int r = rand() % 25 + 65;
        result.push_back(r);
    }
    
    //need to check if at least 3 vowels occur (average 3 vowels per 9 letters)
    //solution should also be applicable for other languages!
    //google -> dont be evil!, build products for everyone! (2Qs, NOT GOOD! no words have 2 qs and qs always come with Us)

    /* for (int i = 0; i< 1000000; i++){
        checkWord("HELLO");
    }
     
     */
    return result;
 }

// Get all different permutations of the letter list you are given =solution
/* to do that you need to check about a million permutations 
- if it starts on a timer, and at end it had a reveal all answers, it would have to run the word check code 
about a million times
- if each check takes 200 milisecs it would take 2 days
- if each check takes 7 ms it would take 2hrs 
*/

std::vector<std::string> powerset(std::string str){
    if (str.size() == 0){
        std::vector<std::string> result;
        result.push_back("");

        return result;
    }
    else{
        char head = str[0];
        std::string tail;
        tail = str.substr (1,std::string::npos);

        std::vector<std::string> res = powerset(tail);
        std::vector<std::string> ans = res;

        for (auto element : res){
            std::string temp = element;
            temp.insert(temp.begin(), head);
            ans.push_back(temp);
        }

        return ans;
    }
}

void permute(std::string a, int l, int r, std::vector<std::string>& results) {

    if (l == r)  {
        results.push_back(a);
    }  
    else {  
        for (int i = l; i <= r; i++) {   
            char temp = a[l];
            a[l] = a[i];
            a[i] = temp;
             
            permute(a, l+1, r, results);  

            temp = a[l];
            a[l] = a[i];
            a[i] = temp;  
        }  
    }  
}  


