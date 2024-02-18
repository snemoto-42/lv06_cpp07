#pragma once

#include <iostream>

template <typename T>
void iter(T* array, size_t len, void (*func)(T &))
{
	if (!array || !func)
		throw std::invalid_argument("Received NULL pointer");
	for (size_t i = 0; i < len; ++i)
		func(array[i]);
}

template <typename T>
void iter(T const* array, size_t len, void (*func)(T const&))
{
	if (!array || !func)
		throw std::invalid_argument("Received NULL pointer");
	for (size_t i = 0; i < len; ++i)
		func(array[i]);
}

template <typename T>
void printElement(T const& element)
{
	std::cout << element << std::endl;
}

template <typename T>
void incrementElement(T& element)
{
	++element;
}
