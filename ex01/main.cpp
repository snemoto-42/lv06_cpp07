#include "iter.hpp"

int main(void)
{
	try
	{
		std::cout << "\n<<< int Test >>>" << std::endl;
		int array[] = {1, 2, 3, 4, 5};
		size_t size = sizeof(array) / sizeof(int);

		std::cout << "print array" << std::endl;
		iter(array, size, printElement<int>);
		std::cout << "increment and print array" << std::endl;
		iter(array, size, incrementElement<int>);
		iter(array, size, printElement<int>);
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "\n<<< double Test >>>" << std::endl;
		double array[] = {1.1, 2.2, 3.3, 4.4, 5.5};
		size_t size = sizeof(array) / sizeof(double);

		std::cout << "print array" << std::endl;
		iter(array, size, printElement<double>);
		std::cout << "increment and print array" << std::endl;
		iter(array, size, incrementElement<double>);
		iter(array, size, printElement<double>);
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "\n<<< std::string Test >>>" << std::endl;
		std::string array[] = {"This", "is", "iter", "test!"};
		size_t size = sizeof(array) / sizeof(std::string);

		std::cout << "print array" << std::endl;
		iter(array, size, printElement<std::string>);
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "\n<<< char Test >>>" << std::endl;
		char array[] = {'a', 'b', 'c', 'd', 'e'};
		size_t size = sizeof(array) / sizeof(char);

		std::cout << "print array" << std::endl;
		iter(array, size, printElement<char>);
		std::cout << "increment and print array" << std::endl;
		iter(array, size, incrementElement<char>);
		iter(array, size, printElement<char>);
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "\n<<< char pointer Test >>>" << std::endl;
		char array_original[] = {'a', 'b', 'c', 'd', 'e'};
		char* array[] = {&array_original[0], &array_original[1], &array_original[2], &array_original[3], &array_original[4]};
		size_t size = sizeof(array) / sizeof(char*);

		std::cout << "print array" << std::endl;
		iter(array, size, printElement<char*>);
		std::cout << "increment and print array" << std::endl;
		iter(array, size, incrementElement<char*>);
		iter(array, size, printElement<char*>);
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "\n<<< char reference Test >>>" << std::endl;
		char array[] = {'a', 'b', 'c', 'd', 'e'};
		size_t size = sizeof(array) / sizeof(char&);

		std::cout << "print array" << std::endl;
		iter(array, size, printElement<char&>);
		std::cout << "increment and print array" << std::endl;
		iter(array, size, incrementElement<char&>);
		iter(array, size, printElement<char&>);
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	// try
	// {
	// 	std::cout << "\n<<< NULL Test >>>" << std::endl;
	// 	char array[] = {'a', 'b', 'c', 'd', 'e'};
	// 	size_t size = sizeof(array) / sizeof(char&);

	// 	iter(NULL, size, printElement<char&>);
	// 	iter(array, size, NULL);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	return 0;
}

// #include <libc.h>
// __attribute__((destructor))
// static void destructor() {
// std::cout << "\n";
// system("leaks -q test");
// }
