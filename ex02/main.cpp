#include <iostream>
#include "Array.hpp"
#include "Array.tpp"
#include <random>

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
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    std::cout << "\ndefault array" << std::endl;
    printArray(numbers);

    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = std::rand();
        numbers[i] = value;
    }
	std::cout << "\noriginal array" << std::endl;
    printArray(numbers);

    Array<int> tmp;
    tmp = numbers;
    Array<int> test(tmp);

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = std::rand();
    }
    std::cout << "\nchanged array" << std::endl;
    printArray(numbers);
    std::cout << "\noroginal deep copy assignment array" << std::endl;
    printArray(tmp);
    std::cout << "\norigonal deep copy constructor array" << std::endl;
    printArray(test);

    tmp = numbers;
    std::cout << "changed deep copy assignment array" << std::endl;
    printArray(tmp);

	std::cout << "\n[] test" << std::endl;
    std::cout << numbers[0] << std::endl;
    ++numbers[0];
    std::cout << numbers[0] << std::endl;

	std::cout << "\nmirror test" << std::endl;
    try
    {
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
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    

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

std::string generateRandomString(int length)
{
    const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<std::size_t> distribution(0, characters.size() - 1);

    std::string randomString;
    for (int i = 0; i < length; ++i) {
        randomString += characters[distribution(generator)];
    }
    return randomString;
}

void stringTest()
{
	std::cout << "\n<<< string Test >>>" << std::endl;
    Array<std::string> strings(MAX_VAL);
    std::cout << "\ndefault array" << std::endl;
    printArray(strings);

    for (int i = 0; i < MAX_VAL; i++)
    {
        const std::string str = generateRandomString(i + 1);
        strings[i] = str;
    }
	std::cout << "\noriginal array" << std::endl;
    printArray(strings);

    Array<std::string> tmp;
    tmp = strings;
    Array<std::string> test(tmp);

    for (int i = 0; i < MAX_VAL; i++)
    {
        const std::string str = generateRandomString(i + 1);
        strings[i] = str;
    }
    std::cout << "\nchanged array" << std::endl;
    printArray(strings);
    std::cout << "\noroginal deep copy assignment array" << std::endl;
    printArray(tmp);
    std::cout << "\norigonal deep copy constructor array" << std::endl;
    printArray(test);

    tmp = strings;
    std::cout << "changed deep copy assignment array" << std::endl;
    printArray(tmp);
}

int main(int, char**)
{
    intTest();
    stringTest();
    return 0;
}

#include <libc.h>
__attribute__((destructor))
static void destructor() {
std::cout << "\n";
system("leaks -q test");
}
