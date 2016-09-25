// my_conditional.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <type_traits>
#include <typeinfo>

namespace cdsim
{
	template<bool b, typename T, typename F>
	struct conditional
	{
		typedef T type;
	};

	template<typename T, typename F>
	struct conditional <false, T, F>
	{
		typedef F type;
	};

};


int main()
{
	typedef cdsim::conditional<true, int, double>::type Type1;
	typedef cdsim::conditional<false, int, double>::type Type2;
	typedef cdsim::conditional<sizeof(int) >= sizeof(double), int, double>::type Type3;

	std::cout << typeid(Type1).name() << '\n';
	std::cout << typeid(Type2).name() << '\n';
	std::cout << typeid(Type3).name() << '\n';

    return 0;
}

