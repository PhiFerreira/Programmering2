// 01.02.24.funksjoner.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int increment(int i);
void increment2(int* i);

void increment(int arr[], size_t size); //void increment(int* arr, size_t size); er det samme
float increment(float f, float inc = 5.5);

int main(int argc, char* argv[])
{
	int number{ 0 };
	int* pToNumber{ &number };

	number = { increment(number) };
	increment2(pToNumber);
	std::cout << number;

	const size_t size{ 5 };
	int arr[] = { 1,2,3,4,5 };
	increment(arr, size);
	for (int x{ 0 }; x < size; ++x) {
		std::cout << "\n" << arr[x] << " ";
	}

	for (int y{ 0 }; y < argc; ++y) {
		std::cout << y << "\t" << argv[y] << "\n";
	}
}

int increment(int i)
{
	return i+1;
}

void increment2(int* i)
{
	(*i)++;
}

void increment(int arr[], size_t size)
{
	for (size_t i{ 0 }; i < size; ++i) {
		arr[i] += 1;
	}
}

float increment(float f, float inc)
{
	return f + inc;
}

/*
int* larger(int a, int b) {
	if (a > b) {
		return &a;                     //Unngå dette fordi du returnere en peker som peker på stacken ikke heap.
									  //Dette gjør at verdien kan være overskrevet når du henter ut verdien.
	}
	else {
		return &b;
	}
}*/ 

int* larger(int a, int b) {
	if (a > b) {
		return new int(a);                     //Gjør evt dette. Men kanskje ikke likevel.
	}
	else {
		return new int(b);
	}
}