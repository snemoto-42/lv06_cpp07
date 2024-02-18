#pragma once

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"

#include <iostream>

template <typename T>
void swap(T & a, T & b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(T const& a, T const& b)
{
	return (b < a) ? b : a;
}

template <typename T>
T max(T const& a, T const& b)
{
	return (b > a) ? b : a;
}
