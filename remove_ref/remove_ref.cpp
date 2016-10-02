// remove_ref.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

namespace cdsim
{
	template<typename T> struct remove_reference	  {	typedef T type;	};
	template<typename T> struct remove_reference <T&> { typedef T type; };
	template<typename T> struct remove_reference <T&&>{	typedef T type;	};
};

template<class T1, class T2>
void print_is_same() {
	std::cout << std::is_same<T1, T2>() << '\n';
}


int main()
{
	std::cout << std::boolalpha;

	print_is_same<int, int>();    // true
	print_is_same<int, int &>();  // false
	print_is_same<int, int &&>(); // false

	print_is_same<int, cdsim::remove_reference<int>::type>();    // true
	print_is_same<int, cdsim::remove_reference<int &>::type>();  // true
	print_is_same<int, cdsim::remove_reference<int &&>::type>(); // true

    return 0;
}

