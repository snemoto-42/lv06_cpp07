#pragma once

#include "Array.hpp"

template <typename T>
Array<T>::Array(): _elements(NULL),_arraySize(0)
{
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n): _arraySize(n)
{
	std::cout << GREEN << "Constructor with argment called" << RESET << std::endl;
	try
	{
		_elements = new T[_arraySize]();
		// for (unsigned int idx = 0; idx < _arraySize; ++idx)
		// 	_elements[idx] = T();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
}

template <typename T>
Array<T>::Array(Array const& other): _arraySize(other._arraySize)
{
	std::cout << GREEN << "Copy constructor called" << RESET << std::endl;
	try
	{
		_elements = new T[_arraySize]();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
	*this = other;
}

template <typename T>
Array<T> & Array<T>::operator=(Array const& other)
{
	std::cout << GREEN << "Copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		delete[] _elements;
		_arraySize = other._arraySize;
		try
		{
			_elements = new T[_arraySize];
			for (unsigned int idx = 0; idx < _arraySize; ++idx)
				_elements[idx] = other._elements[idx];
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	std::cout << GREEN << "Destructor called" << RESET << std::endl;	
	delete[] _elements;
}

template <typename T>
T& Array<T>::operator[](int idx)
{
	if (static_cast<unsigned int>(idx) >= _arraySize)
		throw std::out_of_range("Index out of bounds");
	return _elements[idx];
}

template <typename T>
T const& Array<T>::operator[](int idx) const
{
	if (static_cast<unsigned int>(idx) >= _arraySize)
		throw std::out_of_range("Index out of bounds");
	return _elements[idx];
}

template <typename T>
size_t Array<T>::size() const
{
	return _arraySize;
}
