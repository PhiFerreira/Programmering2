// 02042024_Funksjonspeker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <functional>

long findMaximum(const long* array, size_t size) {
	long maximum = array[0];
	for (size_t i{ 1 }; i < size; ++i) {
		if (array[i] > maximum) {
			maximum = array[i];
		}
	}
	return maximum;
}

long findMinimum(const long* array, size_t size) {
	long minimum = array[0];
	for (size_t i{ 1 }; i < size; ++i) {
		if (array[i] < minimum) {
			minimum = array[i];
		}
	}
	return minimum;
}

template<typename T>
bool less(const T& a, const T& b) {
	return a < b;
}
template<typename T>
bool greater(const T& a, const T& b) {
	return a > b;
}

bool longer(const std::string& a, const std::string& b) {
	return a.length() > b.length();
}
bool shorter(const std::string& a, const std::string& b) {
	return a.length() < b.length();
}

/*template <typename T>
T findOptimum(const T* array, size_t size, bool (*compare)(const T&, const T&)) {
	T optimum = array[0];
	for(size_t i{ 1 }; i < size; ++i) {
		if (compare(array[i], optimum)) {
			optimum = array[i];
		}
	}
	return optimum;
}*/

template <typename T, typename T2>
T findOptimum(const T* array, size_t size, T2 compare) {
	T optimum = array[0];
	for (size_t i{ 1 }; i < size; ++i) {
		if (compare(array[i], optimum)) {
			optimum = array[i];
		}
	}
	return optimum;
}



template <typename T>
class C_less {
public:
	bool operator()(const T& left, const T& right) {
		return left < right;
	}
};

template <typename T>
class C_closest {
private:
	T goal;
public:
	C_closest(T value) :goal{ value } {}
	bool operator()(const T& x, const T& y) {
		return std::abs(x - goal) < std::abs(y - goal);
	}
};

int main()
{
	long (*fun_ptr)(const long*, size_t) { findMaximum };
	long data[] = { 2, 5, 4, 3, 1, 5, 7, 5, 2, 1, 5, 7 };
	//auto fun_ptr = findMaximum; Gjør det samme.
	std::cout << "Value of max: " <<
		fun_ptr(data, std::size(data)) << std::endl;

	fun_ptr = findMinimum;
	std::cout << "Value of min: " <<
		fun_ptr(data, std::size(data)) << std::endl;


	std::cout << "Minimum value is: " <<
		findOptimum(data, std::size(data), less<long>) << std::endl;
	std::cout << "Maximum value is: " <<
		findOptimum(data, std::size(data), greater<long>) << std::endl;


	std::string words[] = { "Fish", "Mammal", "Bird" };
	std::cout << "The first word in alphabetical order is: " <<
		findOptimum(words, std::size(words), less<std::string>) << std::endl;
	std::cout << "The last word in alphabetical order is: " <<
		findOptimum(words, std::size(words), greater<std::string>) << std::endl;

	std::cout << "The longest word is: " <<
		findOptimum(words, std::size(words), longer) << std::endl;
	std::cout << "The shortest word is: " <<
		findOptimum(words, std::size(words), shorter) << std::endl;


	C_less<long> less_obj;
	if (less_obj(3, 5)) {
		std::cout << "3 is less than 5" << std::endl;
	}
	else {
		std::cout << "Something wrong?!" << std::endl;
	}
	std::cout << "Minimum value(by C_less) is: " <<
		findOptimum(data, std::size(data), less_obj) << std::endl;
	std::cout << "First in alphabet(by C_less) is: " <<
		findOptimum(words, std::size(words), C_less<std::string>{}) << std::endl;

	std::cout << "Maximum value(with std::greater<>) is: " <<
		findOptimum(data, std::size(data), std::greater<>{})
		<< std::endl;

	std::cout << "The number closest to '6' is: " <<
		findOptimum(data, std::size(data), C_closest(6)) << std::endl;


	//lambda
	std::cout << "Minimum value(by lambda) is: " <<
		findOptimum(data, std::size(data), [](const long& a, const long& b) {return a < b; }) << std::endl;
	std::cout << "Maximum value(by lambda) is: " <<
		findOptimum(data, std::size(data), [](const long& a, const long& b)->bool {return a > b; }) << std::endl;
}

