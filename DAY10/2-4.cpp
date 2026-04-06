/*
2026년 1학기 STL 월56 화78
4/6 5주 2일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]

#include <iostream>
#include <random>
#include <string>
#include <print>
#include <array>
#include <algorithm>
#include <fstream>
#include <ranges>
#include "save.h"

using namespace std;

default_random_engine dre;
uniform_int_distribution uid{ 0, 999'9999 };
uniform_int_distribution uidName{ 1, 16 };
uniform_int_distribution<> uidChar{ '!', '~' };


class Dog {
public:
	Dog() {
		id = uid(dre);
		int len = uidName(dre);
		for (int i = 0; i < len; ++i) {
			name += uidChar(dre);
		}
	}

	int getid() const {
		return id;
	}

	string getname() const {
		return name;
	}

	string& getname() {
		return name;
	}

private:
	string name;    // [1, 16]
	int id;         // [0, 999'9999]

	friend ostream& operator<<(ostream& os, const Dog& dog) {
		print(os, "[{:7}] - {}", dog.id, dog.name);
		//print(os, "[{:7}]", dog.id);
		return os;
	}
};


array<Dog, 10'0000> dogs;

int main()
{
	ofstream out{ "Dog10만마리", ios::binary };
	out.write((char*)dogs.data(), dogs.size() * sizeof(Dog));


	save("메인.cpp");

}

