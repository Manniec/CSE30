
#include <iostream>

int findMax(int array[]){
    int max = array[0];
    for (int i = 1; i < ???; i++){ //inconvenient that cant ask for size of array . need to take it as a param
        if (array[i] > max){
            max = array[i];
        }
    }
    return max;

}

int findMax2(int array[], int len){
    int max = array[0];
    for (int i = 1; i < len; i++){ //need to take arr length as a separate param
        if (array[i] > max){
            max = array[i];
        }
    }
    return max;

}


int main(){
	int arr[10];
    /* arr disadvantages
        1. The above array is on the stack, do it can not be very large
        2. You cant ask for the size of it bc an arr is a pointer (cant write findMax w out extra param)
        3. arr is just a pointer so no "Out of bounds" errors if you try to assign arr[100] = 50;

    */

    for (int i = 0; i < 10; i++){
        arr[i] = i;
    }

    int max = findMax2(arr, 10);

    arr[107] = 55;





}
/* Solution 
    1. utilize heap for storage using "new" keyword
    2. need to create an object, which has a pointer to some storage, but also stores other useful 
       information (such as the size of the array)
    3. implement some functions to read and manipulate the storage, and that will allow us to
       handle things like out of bounds errors.
*/

/* Implementation

*/

//Public or Private functions in C++
    struct IntegerArray{
        int f(){ //say you have a funciton f that funciton is public

        }
    }
    class IntegerArray{ //if you want to have private fucntions ->
        int f(){

        }
    public:  // everything above this is private, everuthing below is public
        int g(){

        }
    }

struct IntegerArray{
    int* storage;
    int size; 

    IntegerArray(){ //constructor (go in and initialize values)
        size = 10; // new array will have 10 items
        storage = new int[size];
        for(int i = 0; i < size; i++){ // NEED TO INITALIZE SPOTS TO ZERO 
            storage[i] = 0; //(could be poluted with old data if spots not cleared out on construction 
        }

    }
    ~IntegerArray(){// destructor 
        delete[] storage;
    }
    /*
    int&operator[](int index){ // overloading [] operator (now whenever someone uses [], it returns storage[] instead)
        return storage[index]
    }
    */ 
} 


/* Stack Heap organization
Stack:
 - IntegerArray object size:10 size -->HEAP
Heap:
 - 40 bytes (enough room for 10 ints)

 Closing the app -> stack clears, heap stuff stays, 
 Java has a garbage collector that periodicly goes through and cleans up the heap when your done using it
 In C++ you need to clean heap yourself -> destructor

 int main(){
    IntegerArray myArray; // immediately IntegerArray constructor is called
    //code

    std::cout << myArray.size << std::endl; // now you can print size of you object

    // DOESNT WORK :  myArray[1] = 5 //myArray is not an array, but myArray.storage is
    myArray.storage[1] = 5; 

    for(int i = 0; i < myArray.size; i++){
        std::cout << myArray.storage[i] << std::endl; //now always have to use .storage[i] to store data
        // this can be changed with function overloading/operation overloading
    }

   
    //code
    //code

 } // end of funciton destructor for IntegerArray is automatically called (job is to delete stuff in heap)

// CUSTOM CONSTRUCTOR AND []OPERATOR OVERLOAD
struct IntegerArray2{
    int* storage;
    int size; 

    //CONSTRUCTORS
    IntegerArray2(){ // default constructor (go in and initialize values)
        size = 10; // new array will have 10 items
        storage = new int[size];
        for(int i = 0; i < size; i++){ // NEED TO INITALIZE SPOTS TO ZERO 
            storage[i] = 0; //(could be poluted with old data if spots not cleared out on construction 
        }
    }
    IntegerArray2(int s){ // custom constructor that takes int param for size of array
        size = s;
        storage = new int[size];
        for(int i = 0; i < size; i++){ // NEED TO INITALIZE SPOTS TO ZERO 
            storage[i] = 0; //(could be poluted with old data if spots not cleared out on construction 
        }
    }

    //DESTRUCTORS
    ~IntegerArray2(){// destructor 
        delete[] storage;
    }
    int&operator[](int index){ //& means reference (similar to pointer)
        return storage[index]
    }
} 

int main(){
    IntegerArray2 myArray(100000000); // custom constructor called
    // array can be 10000000 or as big as you want (as big as ram will allow) cause now its stored in heap 
    //(takes time but doessnt crash)

    //------------------------code--------------------------------------
    std::cout << myArray.size << std::endl; // now you can print size of you object

    myArray[1] = 5; //myArray is not an array, but myArray.storage is [] operator overloaded
   
    for(int i = 0; i < myArray.size; i++){
        std::cout << myArray[i] << std::endl; //function overloading/operation overloading
    }

     myArray[10000000000001] = 76; // -> crashes when it tries to clean up memory leak, (out of bounds)
    //but allows you to access index 11 even though it doesnt exist still
    // throw exception & stop program before unsafe

 } 

// HANDLEING OUT OF BOUND ERRORS
 struct IntegerArray3{
    int* storage;
    int size; 

    //CONSTRUCTORS
    IntegerArray3(){ // default constructor (go in and initialize values)
        size = 10; // new array will have 10 items
        storage = new int[size];
        for(int i = 0; i < size; i++){ // NEED TO INITALIZE SPOTS TO ZERO 
            storage[i] = 0; //(could be poluted with old data if spots not cleared out on construction 
        }
    }
    IntegerArray3(int s){ // custom constructor that takes int param for size of array
        size = s;
        storage = new int[size];
        for(int i = 0; i < size; i++){ // NEED TO INITALIZE SPOTS TO ZERO 
            storage[i] = 0; //(could be poluted with old data if spots not cleared out on construction 
        }
    }

    //DESTRUCTORS
    ~IntegerArray3(){// destructor 
        delete[] storage;
    }
    int&operator[](int index){ //& means reference (similar to pointer)
        if(index < size){
            return storage[index];
        }else{ //exception handleing (throw exception. doesnt result in memory leak, just stops program there)
            throw std::out_of_range("Array index out of bounds");
        }

    }
} 

int main(){
    IntegerArray2 myArray(6); //constructor 

    //------------------------code--------------------------------------
    std::cout << myArray.size << std::endl; // now you can print size of you object

    myArray[1] = 5; //myArray is not an array, but myArray.storage is [] operator overloaded
   
    for(int i = 0; i < myArray.size; i++){
        std::cout << myArray[i] << std::endl; //function overloading/operation overloading
    }

     myArray[20] = 76; // throw exception & stop program before unsafe

 } //destructor called

 MAKE IT EVEN BETTER!
 - add resizing array functionality (you can make it bigger while program is running 
   because it stored on the heap!)

struct IntegerArray3{
    int* storage;
    int size; 

    //CONSTRUCTORS
    IntegerArray3(){ 
        size = 10; 
        storage = new int[size];
        for(int i = 0; i < size; i++){ // NEED TO INITALIZE SPOTS TO ZERO 
            storage[i] = 0; 
        }
    }
    IntegerArray3(int s){ 
        size = s;
        storage = new int[size];
        for(int i = 0; i < size; i++){ // NEED TO INITALIZE SPOTS TO ZERO 
            storage[i] = 0; 
        }
    }

    //DESTRUCTORS
    ~IntegerArray3(){// destructor 
        delete[] storage;
    }
    int&operator[](int index){ //& means reference (similar to pointer)
        if(index < size){
            return storage[index];
        }else{ 
             //1. create new_storage pointer (points to bigger chunck of memory)
            int* new_storage = new int[index+1]

             //2. make old_storage pointer that points to storage.
            int* old_storage = storage;

             //3. copy everything from old_storage into new_storage that has more room
            for(int i = 0; i < size; i++){
                new_storage[i] = storage[i];
            }

             //4. make storage point to where new_storage is pointing
             storage = new_storage;

             //5. delete where old_storage is pointing
             delete[] old_storage;

             //6. change size element of object (typically make it bigger than just 1 space moreb)
             size = index+1;

             return storage[index]; 
        }

    }
} 

*/