#pragma once

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"

#include <iostream>

template <typename T>
class Array
{
	public:
		Array();
		explicit Array(unsigned int); //explicit コンストラクタが暗黙的な型変換を防ぐために使用
		~Array();
		Array(Array const&);
		Array & operator=(Array const&);

		T & operator[](int) const;
		size_t size(void) const;

	private:
		T* _elements;
		unsigned int _arraySize;
};
