#include <iostream>
#include "mylib.h"

int add(int x, int y){
	return x + y;
}

void printEven(int low, int high){
	for (int i = low; i < high; i++){
		if (i % 2 == 0){
			std::cout << i << std::endl;
		}
		
	}
}
