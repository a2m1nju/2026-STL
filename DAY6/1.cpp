#include <iostream>
#include <random>
#include <fstream>
#include "save.h"
using namespace std;

default_random_engine dre;
uniform_int_distribution uid;

int main()
{
	// [문제] 랜덤 int값 1000개를 화면에 출력하라

	ofstream out("int천만개", ios::binary);

	int num;
	for (int i{}; i < 1000'0000; ++i) {
		// out << uid(dre) << '\n';
		num = uid(dre);
		out.write(reinterpret_cast<char*>(&num), sizeof(int));
	}

	save("메인.cpp");
}