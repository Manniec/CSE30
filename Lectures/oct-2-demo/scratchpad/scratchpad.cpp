#include <iostream>
#include <myLib.h>


int main(){


	return 0;
}
//pointers 
/*
int x = 4; -> variable x storing integer 4
how is this stored in your computer?
blocks of data, each can store one byte (8 bits)
integer -> 4 bytes big (to store a integer it takes 4 blocks)
each sequence of blocks is numbered (1 to __ depends on amount of ram you have)

int* p = &x;
^ pointer called p that gives address of x

- pointer is a variable that stores the adress of another variable. 
- printing p gives a integer hexadecimal 

(long)p -> print as a long integer (typecast)

- if you make 2 integers next to eachother, their pointers should be 4 spaces apart! (bc one int is 4 spaces)
	int x = 4;
	long y = 7;

	long* p = &x;
	long* q = &y;

sizeof(long) --> 8
sizeof(int) --> 4
-----------------------------
So what is p pointing to?
- puting a star infront of pointer name is called a dereference operator 
- dereferincing the pointer tells the compiler to tell us what is the actual data stored in p

*p --> 4 (p is pointing to 4)
*q --> 7 (q is pointing to 7)'

- u can manipulate value through pointer	
	Add 5 to the value p is pointing to 

	*p = *p + 5

	Now x is: 9

What is p pointing to rn?
- x is 9,

	p = p - 1; 

- now p gives you 7. Why?
- changes the pointer to point at the memory location of y instead of x
- difference between manipulating the pointer and manipulating the value stored where the pointer points
- p = p -1 -> point one before yourself (moved 8 spaces bc p is a long!)
- subtracting one doesnt mean subtracting one space, it means move back 8 spaces bc that what it takes to store a long
- moves back to where the pervious long would begin

----------------------------------

long x = 4;
long y = 174;
long z = 12;

- you can access all 3 values with one pointer

long* p = &x;

for(int i = 0; 1 < 3; i++){
	std::cout << *p << std::endl; //p is already pointing at 4, so printing *p right away automatically prints x
	p = p -1; // moves to next long
}
- This is an array! Arrays are pointers and pointers are arrays. There's no difference!



*/