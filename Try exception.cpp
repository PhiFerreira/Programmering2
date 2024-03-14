// Try exception.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
class Trouble {

public:
    Trouble(std::string s = "Something went wrong") :
        message{ s } {}
    std::string what()const { return message; }


private:
    std::string message;

protected:

 
};

class NegativeTrouble : public Trouble{
public:
    NegativeTrouble(std::string s = "Something negative") :
        Trouble{ s } {}

private:

protected:

};

int main()
{
    int test;
    std::cout << "Enter a non-negative number smaller than 6:\t";
    std::cin >> test;


    try {
        if (test > 5) {
            throw Trouble{ "Number is greater than 5" };
        }
        if (test < 0) {
            throw NegativeTrouble{ "Number is lower than 0" };
        }
        else {
            std::cout << "Test is:\t" << test << std::endl;
        }
    }

    catch(const char* message) {
        std::cout << message << std::endl;
    }

    catch (const NegativeTrouble& nt) {
        std::cout << "NegativeTrouble:\t" << nt.what() << std::endl;
    }

    catch (const Trouble& t) {
        std::cout << "Trouble:\t" << t.what() << std::endl;
    }

    catch (...) {
        std::cout << "Unknown exception" << std::endl;
    }


    std::cout << "End of program" << std::endl;

}
