// 13.02.24.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// 
//TEMPLATES

#include <iostream>

template <typename T>               //Lager en funksjon som fungerer for alle datatyper.
T get_max(const T a, const T b) {
    if (a > b) {
        return a;
    }
    return b;
}
template <typename PT>
PT* get_max(PT* a, PT* b) {
    if (*a > *b) {
        return a;
    }
    return b;
}

auto square(const auto x) {
    return x * x; //Forenklet syntax i c++20
}

int main()
{
    int x{ 7 }, y{ 5 };
    double d1{ 9.1 }, d2{ 4.2 };
    std::string s1{ "abc" }, s2{ "ac" };
    std::string s3{ "abc" }, s4{ "ZZ" };
    int *px{ &x }, *py{ &y };


    std::cout << get_max(x, y) << std::endl;
    std::cout << get_max(d1, d2) << std::endl;
    std::cout << get_max(s1, s2) << std::endl;
    std::cout << get_max(s3, s4) << std::endl;

    std::cout << get_max(static_cast<double>(x), d1) << std::endl; //Static caster int'en til double for å få funksjonenen til å fungere
    std::cout << get_max<double>(x, d1) << std::endl;              //Kan også bestemme typen til funksjonen med <type>(<double>)

    std::cout << get_max<int>(d2, d1) << std::endl;                //Kan gjøre dette


    std::cout << get_max(*px, *py) << std::endl;                   //Kan gjøre dette, eller lage en ny template for peker. SE under + PT template.
    std::cout << *get_max(px, py) << std::endl;


    std::cout << square(x) << std::endl;                           //Med den nye metoden fra c++20
    std::cout << square(d2) << std::endl;

}

