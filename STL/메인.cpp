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
#include "save.h"
using namespace std;

default_random_engine dre;
uniform_int_distribution uid{ 0, 999'9999 };
uniform_int_distribution uidName{ 1, 150 };
uniform_int_distribution<> uidChar{ '!', '~' };

// 예제1

class Dog {
public:
	Dog() {
		id = uid(dre);
		int len = uidName(dre);
		for (int i = 0; i < len; ++i) {
			name += uidChar(dre);
		}
	}
private:
	string name;    // [1, 150]
	int id;         // [0, 999'9999]

	friend ostream& operator<<(ostream& os, const Dog& dog) {
		print(os, "[{:7}] - {}", dog.id, dog.name);
		return os;
	}
};


int main() 
{
	for (int i = 0; i < 10; ++i) {
		cout << Dog{} << endl;
	}

	save("메인.cpp");
	
}

