// 27.02.24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Box.h"
#include "Cube.h"


//Flyttet inn i klasse filer '.h ' '.cpp'
/*
class Box {
public:
	//Box() {} //Samme som under
	Box() = default;
	Box(double length, double width, double height) {	}
	double volume();

private:
	double m_length{ 1.0 };
	double m_width{ 1.0 };
	double m_height{ 1.0 };

};

Box::Box(double length, double width, double height) {
	m_length = length;
	m_width = width;
	m_height = height;
}
double Box::volume() {
	return m_length * m_width * m_height;
}

*/

int main()
{
	Box myBox;
	Box* p_box = new Box;
	std::cout << "Volume of 'myBox' is: " << myBox.volume() << std::endl;
	std::cout << "Volume of 'p_box' is: " << (*p_box).volume() << std::endl;
	std::cout << "Volume of 'p_box' is: " << p_box->volume() << std::endl; //Alternativ til den over


	Box newBox(1.0, 2.0, 3.0);
	std::cout << "Volume of 'newBox' is: " << newBox.volume() << std::endl;



	Cube cube1(7.0);
	Cube cube2(3.0);

	std::cout << "Volume of 'cube1' is: " << cube1.volume() << std::endl;
	std::cout << "Volume of 'cube2' is: " << cube2.volume() << std::endl;

	std::cout << "'cube1' is bigger than 'cube2' is: " << cube1.hasLargerVolumeThan(cube2) << std::endl;

	if (cube1.hasLargerVolumeThan(cube1) == true) {
		std::cout << "'cube1' has a larger volume than 'cube2'\n" << std::endl;
	}
	else {
		std::cout << "'cube2' has a larger or equal volume than 'cube1'\n" << std::endl;
	}
	/*
	if (cube1.hasLargerVolumeThan(50) == true) {
		std::cout << "Volume of 'cube1' > 50" << std::endl;
	}
	else {
		std::cout << "Volume of 'cube1' <= 50" << std::endl;
	}
	*/ //This will not work now because I have said that the cube class is only 'explicit'. Therefore it is not possible to pass '50' to this function.

	if (cube1.hasLargerVolumeThan(Cube(50)) == true) {
		std::cout << "Volume of 'cube1' > 50" << std::endl;
	}
	else {
		std::cout << "Volume of 'cube1' <= 50" << std::endl;
	}//This wil work, but now it will compare a cube with sides sized '50', not a cube with volume '50'
}

