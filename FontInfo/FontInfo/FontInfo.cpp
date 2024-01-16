// FontInfo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bitset>

int main()
{
    unsigned short font{ 0b00000110'0'10'01100 };
    std::bitset<16> font_bin(font);
    std::cout << font_bin << std::endl;

    unsigned short size_mask{ 0b00000000'0'00'11111 };
    auto size{ static_cast<unsigned short> (font & size_mask) };
    std::bitset<16> size_bin(size);
    std::cout << size_bin << std::endl;

    unsigned short style_mask{ 0b11111111'0'00'00000 };
    auto style{ static_cast<unsigned short> (font & style_mask) >> 8};
    std::bitset<16> style_bin(style);
    std::cout << style_bin << std::endl;

    unsigned short bold_mask{ 0b00000000'0'01'00000 };
    //auto style{ static_cast<unsigned short> (font & bold_mask) >> 5};
    font |= bold_mask;
    std::bitset<16> font_bin2(font);
    std::cout << font_bin2 << std::endl;

    font &= (~bold_mask);
    std::bitset<16> font_bin3(font);
    std::cout << font_bin3 << std::endl;

    font ^= bold_mask;
    std::bitset<16> font_bin4(font);
    std::cout << font_bin4 << std::endl;


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
