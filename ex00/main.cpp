#include "whatever.hpp"

int main(void)
{
	{
		std::cout << "\n<<< Sample Test >>>" << std::endl;

		int a = 2;
		int b = 3;

		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	{
		std::cout << "\n<<< equal Test >>>" << std::endl;

		std::string c = "chaine1";
		std::string d = c;

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	}
	{
		std::cout << "\n<<< double Test >>>" << std::endl;

		double a = 2.0001;
		double b = 2.0002;

		std::cout << "original : " << "a = " << a << ", b = " << b << std::endl;
		::swap( a, b );
		std::cout << "swap( a, b ) : " << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	}
	{
		std::cout << "\n<<< pointer Test >>>" << std::endl;

		int a_obj = 0;
		int b_obj = 0;
		int* a = &a_obj;
		int* b = &b_obj;

		std::cout << "original : " << "a = " << a << ", b = " << b << std::endl;
		::swap( a, b );
		std::cout << "swap( a, b ) : " << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	}
	{
		std::cout << "\n<<< reference Test >>>" << std::endl;

		int a_obj = 2;
		int b_obj = 3;
		int& a = a_obj;
		int& b = b_obj;

		std::cout << "original : " << "a = " << a << ", b = " << b << std::endl;
		::swap( a, b );
		std::cout << "swap( a, b ) : " << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	}
	return 0;
}

#include <libc.h>
__attribute__((destructor))
static void destructor() {
std::cout << "\n";
system("leaks -q test");
}
