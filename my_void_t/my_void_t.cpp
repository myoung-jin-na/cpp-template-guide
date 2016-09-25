// my_void_t.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <type_traits>
template<class...>
using void_t = void;

template <class T>
struct test{};

template <>
struct test<void> {
	test() { printf("void type template parmeter\n"); }
};

template <class A, class B>
void test(A<B> a)

int main()
{
	printf("%d", (int)std::is_same<void_t<int>, void>::value);
	test<void_t<int> > a;
	test<void> b;
	return 0;
}

