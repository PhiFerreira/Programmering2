// Template_klasser.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Array.h"


int main()
{
	try {
		const size_t numValues = 10;
		Array<int> my_arr(numValues);
		
		for (size_t i{ 0 }; i < numValues; ++i) {
		my_arr[i] = i;
		}

		const Array<int> other_array{ my_arr }; //Må lage en copy-constructor. Hvis ikke kopierer den pekeren, så det blir i essens samme array ikke to.


		my_arr[0] = 7;
		std::cout << my_arr[0] << std::endl;

		std::cout << other_array[5] << std::endl; //Får ikke initielt lov til å skrive ut variabler til et const array. Må overlaste operator[] med const return og const funksjon

	}
	catch (std::out_of_range& ex) {
		std::cout << "Out of range error: " << ex.what() << std::endl;
	}

	

}
