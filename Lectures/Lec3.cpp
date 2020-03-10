/*
All user interfaces will be done in HTML (buttons, text fields, and such)

Html is just formating, so you can't program logic into html, you would need javascript

Static directory, main.js, will store functions. Html client side will ask server for the response. 

From now on all examples will be in client server model.

server.cpp:
CROW_ROUTE(app, "/fileroutebleh")
    ([](
    ){

    });

Note: when browser receives something with no html it just displays it as is (no formating/ui)


You can't send everything as a string, because thats only one piece of information. 
So you send it in JSON (JavaScript Object Notation). 

JSON: objects consist of key-value pairs enclosed by curly brackets (associative array)
{"num1" : 7, "num2" : 12, "word" : "GOOGLE", "collection" : [1,2,3,4,5], "user" : {"name" : "Joe", "email" : "joe@gmail.com"}}

- you can nest json objects within json objects
- messy so pretty print

Say you name the json object (assign it to a variable):
data = {
    "num1" : 7, 
    "num2" : 12, 
    "word" : "GOOGLE", 
    "collection" : [1,2,3,4,5], 
    "user" : {"name" : "Joe", "email" : "joe@gmail.com"}
}

Then you can access values using their keys
    data["num1"] => 7
    data["word"] => 12
    data["collection"] => [1,2,3,4,5]


So if you need multiple values from the ui, you have it return a json object instead 
(JSONify everything your app returns from the browser)

-----------------------------------------------------------------------------------------------------
Google interview question: 
Given an array of characters, how many copies of the word "GOOGLE" can you make?

Examples:
[ A, B, C] => 0
[G, G, O, O, L, L, E, E] => 1

Solution:
- Count the number of Gs, Os, Ls, and Es in the array
    G - 2
    O - 2
    L - 2
    E - 2
- Take the number of G's, divide by 2 (because there are 2 G's in Google). Repeat the division by
  the number of times the letter appears in the word "GOOGLE". (NEED TO KNOW HASHTABLES!)
    G - 2 -> 1
    O - 2 -> 1
    L - 2 -> 2
    E - 2 -> 2
- Take the minimum value: which is 1
-----------------------------------------------------------------------------------------------------

CROW_ROUTE(app, "/json")
  ([](
    ){
        std::string word = "GOODLE";
        std::vector<char> letters; // empty array
            // to look for google in array ["A", "B", "C"] say
            // std::vector<char> letters = ["A", "B", "C"] ;

        int count = countPossibleSubstrings(word, letters); 
        // funciton countPossibleSubstrings() will be found in myLib.cpp and myLib.h

        //C++ json object (use library crow which has built in json type)
        crow::json::wvalue data;

        data["word"] = word;
        data["count"] = count; 
        // creates data = {"word" : "GOOGLE", "count" : 0}

        std::string response; // remember that you can only send strings, but now string will be in json format
        crow::json::dump_internal(data, response);


    });



JS FILE:
function clickJSON(){ // define function that rearranges string for html output
	var xhttp = new XMLHttpRequest();

	xhttp.onreadystatechange = function() {
		if (this.readyState == 4 && this.status == 200) {
		   // Typical action to be performed when the document is ready:
		   // alert(xhttp.responseText);
		   var ansSpace = document.getElementById("ans");

		   var data = JSON.parse(xhttp.responseText);
		   
		   ansSpace.innerHTML = "Word: " + data["word"] + " appears " + data["count"] + " times.";
		}
	};
	var string = "/json" //specifies datatype
	xhttp.open("GET", string, true);
	xhttp.send();
}

WRITE UNIT TESTS FIRST:
Context(CountFunction){
    std::string word = "GOOGLE"; //word same for all tests

    Spec(None) {
        std::vector<char> letters = ["A","B", "C"];
        Assert::That(countPossibleSubstrings(word, letters), Equals(0));
    }

    Spec(One){
        std::vector<char> letters = ["G","O", "O", "G", "L", "E"];
        Assert::That(countPossibleSubstrings(word, letters), Equals(1));
    }

    Spec(OneOfEach) {
        std::vector<char> letters = ["G","O", "L", "E"];
        Assert::That(countPossibleSubstrings(word, letters), Equals(0));
    }

    Spec(Scrambled) {
        std::vector<char> letters = ["L","O", "E", "G", "G", "O"];
        Assert::That(countPossibleSubstrings(word, letters), Equals(1));
    }
}
*/