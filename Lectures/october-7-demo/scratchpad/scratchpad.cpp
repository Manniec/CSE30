#include <iostream>
#include <myLib.h>

int main(){

	int z = 6;
	int y = 7;
	int x = 12;

	int* p = &x;

	// The four variables defined above, make up an array of 3 elements

	std::cout << *p << std::endl;

	p++; //moves 4 spaces right (hits the begining of every number)

	std::cout << *p << std::endl;

	p++;

	std::cout << *p << std::endl;

	


	

	return 0;
}
