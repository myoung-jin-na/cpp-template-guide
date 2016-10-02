// max.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

template<typename T>
inline T const& max(T const& a, T const& b)
{
	return a > b ? a : b;
}

inline int const& max(int const& a, int const& b)
{
	return a > b ? a : b;
}

template<typename T>
inline T const& max(T const& a, T const& b, const& c)
{
	return ::max(::max(a, b), c);
}


int main()
{
	std::cout << max(1, 2) << std::endl;
    return 0;
}

