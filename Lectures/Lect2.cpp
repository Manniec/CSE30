// basic c++ program

#include <iostream> 

using namespace std;

//defining function
int add(int x, int y){
    return x + y;
}
void printEven(int low, int high){
     for (int i = low; i < high; i++){
        if (1 % 2 == 0){ // PRINTS ALL EVEN NUMBERS
            cout << i << endl;
        }
    }
}

//main function runs first
int main() {
    cout << "Hello World" << endl;

    // for loop
    for (int i = 0; i < 10; i++){
        // if statement
        if (1 % 2 == 0){ // PRINTS ALL EVEN NUMBERS
            cout << i << endl;
        }
        
    }

    //calling function
    int num = add(10, 3);

    cout << i << endl;
    return 0;
}

/*
Good programing practice!
1. Don't have long main functions. Break up code into additional functions that you can call in main().
2. Defining functions should be done in a separate file. Defining functions in same file makes it appear 
   messy, but it also is not very testable. You should be able to run the code multiple times with multiple
   different inputs. (testing the entire program is not a good idea. Unit tests!)
   Each function should be a unit. 
3. Header files (.h file). What goes inside a c++ header file is the signature of a function (not the funciton itself)
   Signature of the funciton is its name, return type, and paramaters 
   Example: int add(int x, int y);
            void printEven(int low, int high);
   A fuction signature is all you need to call the function (its not the actual function)
   To use the functions, at the top of the code add:
         #include "mylib.h"
4. Function definiton should be put in a separate cpp file of the same name as the header file.
   Must have:
         #include <iostream> 
         using namespace std;
   Entire function defintion is saved in the mylib.cpp file while the headers are saved in the mylib.h header file.
5. When you are compiling in the terminal you should type 
         g++ demo.cpp mylib.cpp - o demo 
         ./demo
   (must include all cpp files it takes to run)
6. Makefile, a text file with the terminal commands in it. 
     all:
         g++ demo.cpp mylib.cpp - demo
     clean:
         rm -f demo //deletes demo file
   Calling make clean (will run what is under clean:)
   Calling make (will run what is under all:)
7. Test first development: make unit tests, fail all of them with empty functuons, then write the functions to 
   pass all the tests. 

8. igloo.h file in igloo folder can be called by #include <igglo/igloo.h>. Everytime you change the program the igloo framework
    will  check if it passes the test cases. (test frame work only works including .h files not .cpp files)
9. test.cpp containts a 
    Context(){
        Spec(SimpleTest){
            Assert::That
        }
    }
10. Command to compile the test file is: 
        g++ test.cpp mylib.cpp -o test -I. -w
    The -o defines the name of the executable created. Not including -o creates a file called a.out.
    Executable can be run with command ./test
    If you are including stuff that is not included in your compiler, such as igloo, you need to tell 
    it where to look (thats the -I. part, tells it to look for them in the current folder)
    If you dont want the compiler to show you warnings add -w to the command
    Once your test file call works, you can add it to your make file:
        test:
            g++ test.cpp mylib.cpp -o test -I. -w
        clean:
            rm -f demo
            rm -f test
11. Dockerfile
*/





