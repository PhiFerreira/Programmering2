// 15.02.24 - modules - namespace.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
import mymath;

int main()
{
    std::cout << square(4.5) << std::endl;
    std::cout << square(lambda) << std::endl;
    int number{ 4 };
    if (getOddity(number) == Oddity::Even) {
        std::cout << number << " is even" << std::endl;
    }
    else {
        std::cout << number << " is odd" << std::endl;
    }
}


