// 27.02.24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <typeinfo>
#include "Box.h" // Nå kan den ende opp med å kall Box.h flere ganger(inne i carton.h også) i andre programmer kan dette ikke være lov. Evt. ta bort box.h når en har carton.h
#include "Cube.h"
#include "Carton.h"
#include "ToughPack.h"


//Don't do this unless you absolutely need to:
//You go inside the Box "function" and tell it that this function is a "friend" and therefore can access the private variables.
double surfaceArea(const Box& b) {
	return 2.0 * (b.m_length * b.m_width) + 2.0 * (b.m_length * b.m_height) + 2.0 * (b.m_height * b.m_width);
}





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
	/*
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

	if (cube1.hasLargerVolumeThan(50) == true) {
		std::cout << "Volume of 'cube1' > 50" << std::endl;
	}
	else {
		std::cout << "Volume of 'cube1' <= 50" << std::endl;
	}
	*/ //This will not work now because I have said that the cube class is only 'explicit'. Therefore it is not possible to pass '50' to this function.
	/*
	if (cube1.hasLargerVolumeThan(Cube(50)) == true) {
		std::cout << "Volume of 'cube1' > 50" << std::endl;
	}
	else {
		std::cout << "Volume of 'cube1' <= 50" << std::endl;
	}//This wil work, but now it will compare a cube with sides sized '50', not a cube with volume '50'


	std::cout << "\n\n" << std::endl;

	Box myBox(4);
	std::cout << myBox.volume() << std::endl;

	std::cout << "\n" << std::endl;

	Box b2{ myBox };
	std::cout << b2.volume() << "\n\n" << std::endl;

	//std::cout << myBox.m_length << std::endl; //Can't initially read this variable because of "private"(box.h)
	myBox.set_height(239);
	myBox.set_width(7);
	std::cout << myBox.get_length() << std::endl;
	std::cout << myBox.get_width() << std::endl;
	std::cout << myBox.get_height() << std::endl;

	//myBox.set_length(3.4)->set_width(34)->set_height(39) //Is using the Box* function insted of void in .cpp


	std::cout << "\nThere is currently: " << myBox.get_object_count() << " Box objects." << std::endl;

	const Box constBox(1, 4, 2);
	//constBox.set_height(23); //Can't set height because Box is 'const'
	std::cout << constBox.volume() << std::endl; //Doesn't work initially. But works now because I changed the volume() function to 'const'.

	std::cout << "\n\nThe surface area of myBox is: " << surfaceArea(myBox) << std::endl;

	std::cout << "\n" << std::endl;

	Box* p_b = new Box(3.4);
	delete p_b;
	p_b = nullptr;
	std::cout << "There is currently: " << myBox.get_object_count() << " Box objects." << std::endl;
	
	Box b1(2.9, 3.6, 4.0);
	Box b2(1.9, 3.2, 4.0);
	if (b2 < b1) {
		std::cout << "b2 is smaller than b1" << std::endl;

	}

	if (b2.operator<(b1)){
		std::cout << "b2 is smaller than b1" << std::endl;
	}

	if (b1 < 889.7) {
		std::cout << "b1 is smaller than 889.7" << std::endl;
	}

	if (13.2 < b1) {
		std::cout << "13.2 is bigger than b1" << std::endl;
	}

	if (b1 == b1) {
		std::cout << "b1 is equal to b1" << std::endl;
	}

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;

	Box b3 = b1 + b2;
	std::cout << b3 << std::endl;

	std::cout << "\n\n" << std::endl;
	std::cout << ++b3 << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << b3++ << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << b3 << std::endl;
	*/
	/*
	Carton c1{ "Metal" };
	std::cout << c1.volume() << std::endl;

	Carton c2{ 2.1, 3.9, 4.7, "Plastic" };
	std::cout << c2.volume() << std::endl;

	Carton c3 = c2;
	std::cout << c3.volume() << std::endl;*/
	
	Box b(2.0, 2.0, 2.0);
	ToughPack tp(2.0, 2.0, 2.0);

	std::cout << "Volume of Box is:\t" << b.volume() << "\nVolume of ToughPack is:\t" << tp.volume() << std::endl;

	Box* p_box{ &tp };
	//std::cout << "Volume of 'tp' through Box-pointer is:\t\t" << p_box->volume() << std::endl;
	std::cout << "Volume of 'tp' through Box-pointer is(When using 'virtual' on Box's volume function:\t" << p_box->volume() << std::endl;
	ToughPack* p_tp{ &tp };
	std::cout << "Volume of 'tp' through ToughPack-pointer is:\t\t\t\t\t\t" << p_tp->volume() << std::endl;

	std::vector<Box> boxes;
	boxes.push_back(b);
	boxes.push_back(tp);
	boxes.push_back(Carton(3.0, 3.0, 3.0, "Plastic"));

	for (const auto& element : boxes) {
		std::cout << "Volume is:\t" << element.volume() << std::endl;
	}


	std::vector<std::unique_ptr<Box>> box_ptrs;
	box_ptrs.push_back(std::make_unique<Box>(2.0, 2.0, 2.0));
	box_ptrs.push_back(std::make_unique<ToughPack>(2.0, 2.0, 2.0));
	box_ptrs.push_back(std::make_unique<Carton>(2.0, 2.0, 2.0, "Metal"));

	for (const auto& element : box_ptrs) {
		std::cout << "Volume is:\t" << element->volume() << std::endl;
	}

	std::cout << typeid(p_tp).name() << std::endl;
	std::cout << typeid(*p_tp).name() << std::endl;

	//virtual double volume() const = 0; //Lagrer er til oblig3



}

