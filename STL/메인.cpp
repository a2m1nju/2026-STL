/*
2026년 1학기 STL 월56 화78
3/23 3주 2일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// 많은 수의 자료 다루기 - FILE I/O - binary I/O - class 객체

#include <iostream>
#include <algorithm>
#include <random>
#include <print>
#include <string>
#include <array>
#include <fstream>
#include "save.h"
using namespace std;

default_random_engine dre;
uniform_int_distribution uid{ 0, 9999 };
uniform_int_distribution uidNameLen{ 10, 30 };
uniform_int_distribution<int> uidChar{ 'a', 'z' };

class Dog {
public:
	Dog() {
		id = uid(dre);
		int len = uidNameLen(dre);
		for (int i = 0; i < len; ++i) {
			name += uidChar(dre);
		}
	}


private:
	string name;  // [10, 30] 사이의 소문자로 구성된 이름
	size_t id;    // [0, 9999]

	friend ostream& operator <<(ostream& os, const Dog& dog) {
		print(os, "[{:>4}] - {} ", dog.id, dog.name);
		return os;

	}
};

int main()
{
	array<Dog, 1000> dogs;

	ofstream out{ "dog천마리",ios::binary };
	out.write((char*)dogs.data(), dogs.size() * sizeof(Dog));



	save("메인.cpp");
}
