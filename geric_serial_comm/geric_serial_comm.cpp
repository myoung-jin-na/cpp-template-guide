// geric_serial_comm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

struct SParser {
	template<typename... Fns>
	bool run(const char* msg) {
		return (true && ...&&Fns::apply(msg));
	};
};

struct check1 {
	static bool apply(const char* msg) {
		std::cout << "#1" << std::endl;
		return true;
	};
};

struct check2 {
	static bool apply(const char* msg) {
		std::cout << "#2" << std::endl;
		return true;
	};
};

void MyParseFunc(std::string& s)
{
	SParser m;
	m.run<check1, check2>(s.c_str());
	m.run<check2, check1>(s.c_str());
}

int main()
{
	std::string s{ "Hellow" };
	MyParseFunc(s);

	return 0;
}

