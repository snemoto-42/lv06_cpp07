#include <iostream>
#include "Array.hpp"
#include "Array.tpp"

#define MAX_VAL 5

template<typename T>
void printArray(Array<T> const& a)
{
	std::cout << ">>>" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
        std::cout << a[i] << std::endl;
	std::cout << "<<<" << std::endl;
}

void intTest()
{
	std::cout << "\n<<< int Test >>>" << std::endl;
    Array<int> numbers(MAX_VAL);
    srand(static_cast<unsigned int>(time(NULL)));
    std::cout << "\ndefault array" << std::endl;
    printArray(numbers);

    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
    }
	std::cout << "\noriginal array" << std::endl;
    printArray(numbers);

    Array<int> tmp;
    tmp = numbers;
    Array<int> test(tmp);

    std::cout << "\nchanged array" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    printArray(numbers);
    std::cout << "\noroginal deep copy assignment array" << std::endl;
    printArray(tmp);
    std::cout << "\norigonal deep copy constructor array" << std::endl;
    printArray(test);

	std::cout << "\nmirror test" << std::endl;
    int* mirror = new int[MAX_VAL];
    for (int i = 0; i < MAX_VAL; i++)
        mirror[i] = numbers[i];
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
            std::cerr << "didn't save the same value!!" << std::endl;
        else
            std::cout << i << " index is the same" << std::endl;
    }
    delete [] mirror;

	std::cout << "\n<<< Error Test >>>" << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main(int, char**)
{
    intTest();
    return 0;
}

#include <libc.h>
__attribute__((destructor))
static void destructor() {
std::cout << "\n";
system("leaks -q test");
}
