/*
Last time we left of with creating he countPossibleSubstrings() function:
- Next step is does this code work in every case or is it limited in some cases?
- How can it be improved? 

Generalizing your solution:
- right now it only works for the word Google. How can we generalize it to work for any word?

Go to user interface:
- add place to accept user input in HTML page
- pass form front end to backend as JSON
- If statements: if user given me word, then continue
- Tell javascript to pass along the information (first hardcode into url)
    var string = "/json?word=GOOGLE&letters[]=G&letters[]=O&letters[]=O&letters[]=G&letters[]=L&letters[]=E"

    To pass it onto the server write a function to turn the userinput into the url)
    -OR-
    Use JQuery

JQuery
- $.get() -> preform a get request 
- give it the url, the data that should be passed along, and give it the function that will be executed if 
  correct
    $.get("/json", {}, function(response){ \\feeding it a url path, a empty json object, and a function

    });

    $.get("/json", {"word" : "GOOGLE", "letters" : ["G", "O", "O", "G","L", "E"]}, function(response){
        $("#ans").html(response["word"]+ " : " + response["count"]);
    });

JS Function:
1: Still in hard coded stage

    function clickCalculate(){
    var dataToSend = {"word" : "GOOGLE", "letters" : ["G", "O", "O", "G","L", "E"]};

        $.get("/json", dataToSend, function(response){
            $("#ans").html(response["word"]+ " : " + response["count"]);
        });

    }

2: 


    function clickCalculate(){

        var theWord = $("#wordInput").val(); 
        \\go to html, find textbox with id(denoted#) of wordInput, and take its input 

        console.log(theWord);

        var dataToSend = {"word" : theWord, "letters" : ["G", "O", "O", "G","L", "E"]}; 
            //Now instead of "GOOGLE" you can use the variable theWord

        //-------------JQUERY that sends input to server ----------------
        $.get("/json", dataToSend, function(response){
            $("#ans").html(response["word"]+ " : " + response["count"]);
        });

    }

3:

 function clickCalculate(){

        var theWord = $("#wordInput").val(); 

        var theList = $("#listInput").val();
        //because list must be in form ["a", "b", "c"] instead of "a,b,c"

        function strToJson(str){
            str = '['+ str + ']';
            str = 

        }

        console.log(theWord);

        var dataToSend = {"word" : theWord, "letters" : ["G", "O", "O", "G","L", "E"]}; 
            //Now instead of "GOOGLE" you can use the variable theWord

        //-------------JQUERY that sends input to server ----------------
        $.get("/json", dataToSend, function(response){
            $("#ans").html(response["word"]+ " : " + response["count"]);
        });

    }

Hashtables
- A hashtable is a collection of key value pairs (lhs is the key, the rhs is a value)
- An array indexed with non integers (labled data)
- If an array's label is [0:5, 1:7, 2:3, 3:1, 4:8]
- Instead of labeling/indexing with integers, you can use strings or characters (key)
- Google example:

    Array : arr = [5,7,3,1,8]
    arr[1]  => 7 (7 is the 1th element of the array)

    ht = {
        "G" : 2,
        "O" : 2,
        "L" : 1,
        "E" : 1, 
    }
    ht['O'] => 2
    ht['L'] => 1

- key is not limited to a character it can be full strings like 'john'
- this is not how its written in c++ its just a visualization of the concept
- in C++
    std::unordered_map<keyDataType, valDataType> nameOfHash;

Using Hashtables to build new generalized countPossibleSubstrings:

    int countPossibleSubstrings(std::string word, std::vector<char>letters){

        std::unordered_map<char, int> needed; //make HT for needed letters

        // 1. first check if first letter of word appears in the hashtable
        for (int i = 0; i < word.size(); i++){ // in C++ word.size() gives length of string word
            auto check = needed.find(word[i]);
            // ^DOESNT RETURN A BOOLEAN (which is why data type auto)
                //in C++ if not in there the pointer searching for the character will 
                //point just beyond the end of the hashtable so use needed.end()
            if (check == needed.end()){ 
                //Did not find it
                needed.insert({word[i]})
            } else {
                //Found it
                needed[word[i]]++;
            }
        }

        //How do you iterate over a hashtable
        for (auto element: needed){
            std::cout << element.first << ": "<< element.second <<
            std::endl;
        }
    }

- why is it ok that order doesnt matter for hashtables? bc order is a "magic number". IF it means something
  to you the one who wrote it it might not mean anything to anyone whose reading the code.

Scratchpad:

    #include <iostream>
    #include <string>
    #include <myLib.h>

    int main(){
        std::string word = "APPLE"
        std::vector<char> letters = {'X', 'Y'};

        int x = countPossibleSubstrings(word, letters);
        return 0;
    }


   


    
   

*/