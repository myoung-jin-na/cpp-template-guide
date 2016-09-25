// my_is_array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

namespace cdsim
{
	template <class...T>
	struct is_array : std::false_type
	{
	};

	template<class T>
	struct is_array<T[]> : std::true_type
	{
	};

	template<class T, int N>
	struct is_array<T[N]> : std::true_type
	{
	};

	//static bool is_array<class T...>::value = false;

};

class A {};

int main()
{
	std::cout << std::boolalpha;
	std::cout << cdsim::is_array<A>::value << '\n';
	std::cout << cdsim::is_array<A[]>::value << '\n';
	std::cout << cdsim::is_array<A[3]>::value << '\n';
	std::cout << cdsim::is_array<float>::value << '\n';
	std::cout << cdsim::is_array<int>::value << '\n';
	std::cout << cdsim::is_array<int[]>::value << '\n';
	std::cout << cdsim::is_array<int[3]>::value << '\n';
}

