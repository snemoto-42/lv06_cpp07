#include "iter.hpp"

int main(void)
{
	std::cout << "\n<<< not-const array Test >>>" << std::endl;
	try
	{
		std::cout << "\n<<< int Test >>>" << std::endl;
		int array[] = {1, 2, 3, 4, 5};
		size_t size = sizeof(array) / sizeof(int);

		std::cout << "print array" << std::endl;
		iter(array, size, printElement);
		std::cout << "increment and print array" << std::endl;
		iter(array, size, incrementElement);
		iter(array, size, printElement);
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
		iter(array, size, printElement);
		std::cout << "increment and print array" << std::endl;
		iter(array, size, incrementElement);
		iter(array, size, printElement);
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
		iter(array, size, printElement);
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
		iter(array, size, printElement);
		std::cout << "increment and print array" << std::endl;
		iter(array, size, incrementElement);
		iter(array, size, printElement);
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
		iter(array, size, printElement);
		std::cout << "increment and print array" << std::endl;
		iter(array, size, incrementElement);
		iter(array, size, printElement);
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
		iter(array, size, printElement);
		std::cout << "increment and print array" << std::endl;
		iter(array, size, incrementElement);
		iter(array, size, printElement);
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n<<< const array Test >>>" << std::endl;
	try
	{
		std::cout << "\n<<< int Test >>>" << std::endl;
		const int array[] = {1, 2, 3, 4, 5};
		size_t size = sizeof(array) / sizeof(int);

		std::cout << "print array" << std::endl;
		iter(array, size, printElement);
		// std::cout << "increment and print array" << std::endl;
		// iter(array, size, incrementElement);
		// iter(array, size, printElement);
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "\n<<< double Test >>>" << std::endl;
		const double array[] = {1.1, 2.2, 3.3, 4.4, 5.5};
		size_t size = sizeof(array) / sizeof(double);

		std::cout << "print array" << std::endl;
		iter(array, size, printElement);
		// std::cout << "increment and print array" << std::endl;
		// iter(array, size, incrementElement);
		// iter(array, size, printElement);
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "\n<<< std::string Test >>>" << std::endl;
		const std::string array[] = {"This", "is", "iter", "test!"};
		size_t size = sizeof(array) / sizeof(std::string);

		std::cout << "print array" << std::endl;
		iter(array, size, printElement);
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "\n<<< char Test >>>" << std::endl;
		const char array[] = {'a', 'b', 'c', 'd', 'e'};
		size_t size = sizeof(array) / sizeof(char);

		std::cout << "print array" << std::endl;
		iter(array, size, printElement);
		// std::cout << "increment and print array" << std::endl;
		// iter(array, size, incrementElement);
		// iter(array, size, printElement);
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "\n<<< char pointer Test >>>" << std::endl;
		const char array_original[] = {'a', 'b', 'c', 'd', 'e'};
		const char* array[] = {&array_original[0], &array_original[1], &array_original[2], &array_original[3], &array_original[4]};
		size_t size = sizeof(array) / sizeof(char*);

		std::cout << "print array" << std::endl;
		iter(array, size, printElement);
		// std::cout << "increment and print array" << std::endl;
		// iter(array, size, incrementElement);
		// iter(array, size, printElement);
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "\n<<< char reference Test >>>" << std::endl;
		const char array[] = {'a', 'b', 'c', 'd', 'e'};
		size_t size = sizeof(array) / sizeof(char&);

		std::cout << "print array" << std::endl;
		iter(array, size, printElement);
		// std::cout << "increment and print array" << std::endl;
		// iter(array, size, incrementElement);
		// iter(array, size, printElement);
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// // try
	// // {
	// // 	std::cout << "\n<<< NULL Test >>>" << std::endl;
	// // 	char array[] = {'a', 'b', 'c', 'd', 'e'};
	// // 	size_t size = sizeof(array) / sizeof(char&);

	// // 	iter(NULL, size, printElement<char&>);
	// // 	iter(array, size, NULL);
	// // }
	// // catch(const std::exception& e)
	// // {
	// // 	std::cerr << e.what() << '\n';
	// // }
	return 0;
}

// #include <libc.h>
// __attribute__((destructor))
// static void destructor() {
// std::cout << "\n";
// system("leaks -q test");
// }
