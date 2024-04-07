#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
//#include<newdelete/newdelete.hpp>


#include<iostream>

int plus(int a) {
	return a + 1;
}

int plusplus(int a) {
	return (a + 1 + 1);
}

int main(){
	int a = 5;
	int b = a + 3;
	int result1 = plus(a);
	int result2 = plusplus(a);
	std::cout << result1 << " " << result2;
	return 0;
}