#pragma once

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"

#include <iostream>

template <typename T, typename Func>
void iter(T* array, size_t len, Func func)
{
	for (size_t i = 0; i < len; ++i)
		func(array[i]);
}

template <typename T>
void printElement(const T& element)
{
	std::cout << element << std::endl;
}

template <typename T>
void incrementElement(T& element)
{
	++element;
}
