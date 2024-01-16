// 16.01.24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";

    wchar_t ch{ L'å' }; // Får lagt til "å" men den printer ikke ut "å". Kan få det til ved å lage egen GUI.
    std::wcout << ch << std::endl;

    auto test1{ 10 };
    auto test2{ 10L };

    std::cout << typeid(test1).name() << " " << typeid(test2).name() << std::endl;

    auto test3{ static_cast<unsigned short>(test1) };
    std::cout << typeid(test3).name() << " " << test3 << std::endl;

    auto test4{ (test3 << 1) };
    auto test5{ (test3 >> 1) };
    auto test6{ (test5 << 1) };
    std::cout << test4 << std::endl;
    std::cout << test5 << std::endl;
    std::cout << test6 << std::endl;

    enum class day { mon, tue, wed, thu, fri, sat, sun };
    enum class punctuation : char { Comma = ',', Question = '?' };

    using BigOnes = unsigned long long;
    BigOnes Num{ 3432423324 };
    std::cout << typeid(Num).name() << " " << Num << std::endl;

    typedef unsigned long long BigOnes;
}


















// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
