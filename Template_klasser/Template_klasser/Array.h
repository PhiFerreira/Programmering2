#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

template <typename T>
class Array {
public:
	explicit Array<T>(size_t size);
	Array<T>(const Array& array);
	~Array();
	T& operator[](size_t index);
	const T& operator[](size_t index) const;
	

private:
	T* m_elements;
	size_t m_size;


protected:
};



template<typename T>
Array<T>::Array(size_t size)
	:m_elements{new T[size]}, m_size{size}
{
	std::cout << "Constructor called" << std::endl;
}

template<typename T>
Array<T>::Array(const Array& array)
	:m_elements{ new T[array.m_size] }, m_size{ array.m_size }
{
	//m_elements = new T[m_size];
	for (size_t i = 0; i < m_size; ++i) {
		m_elements[i] = array.m_elements[i];
	}
}

template<typename T>
Array<T>::~Array()
{
	delete[] m_elements;
	std::cout << "Destructor called" << std::endl;
}

template<typename T>
T& Array<T>::operator[](size_t index)
{
	/*if (index >= m_size) {
		throw std::out_of_range("Index does not exist. Index entered: " + std::to_string(index));
	}
	return m_elements[index];*/
	return const_cast<T&>(static_cast<const Array<T>&>(*this)[index]); //Dette kan gjøres for å slippe å kopiere kode. Spesielt hvis koden blir lang. Fuck-up-factor == HØY!
}

template<typename T>
const T& Array<T>::operator[](size_t index) const
{
	if (index >= m_size) {
		throw std::out_of_range("Index does not exist. Index entered: " + std::to_string(index));
	}
	return m_elements[index];

}


//Tips til oblig. Lage destruktør, sette pekere til nullptr ved behov.