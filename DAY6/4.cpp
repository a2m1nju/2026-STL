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
#include <filesystem>
#include "save.h"
using namespace std;

default_random_engine dre;
uniform_int_distribution uid{ 0, 9999 };
uniform_int_distribution uidNameLen{ 10, 30 };
uniform_int_distribution<int> uidChar{ 'a', 'z' };

class Dog {
private:
	string name;  // [10, 30] 사이의 소문자로 구성된 이름
	size_t id;    // [0, 9999]

	friend ostream& operator <<(ostream& os, const Dog& dog) {
		print(os, "[{:>4}] - {} ", dog.id, dog.name);
		return os;
	}

	friend istream& operator >> (istream& is, Dog& dog) {
		is.read((char*)&dog, sizeof(Dog));
		return is;
	}
};

// [문제] 파일 "Dog천마리"에는 class Dog 객체 1000마리가 저장되어있다.
// 파일은 binary모드이고 각 객체는 메모리 크기 그대로 stream의 write함수로 기록하였다
// 모든 객체를 한번의 write함수로 기록하였다.
// Dog의 맴버는 위의 코드와 같다
// 메모리에 모두 읽어오시오
// 메모리에 읽은 모든 Dog를 화면 출력하라.


int main()
{
	Dog dog;
	array<Dog, 1000> dogs;

	ifstream in{ "Dog천마리", ios::binary };
	if (not in) {
		cout << "dog no" << endl;
		return 111;
	}

	array<Dog, 1'000> dogs;
	in.read((char*)dogs.data(), dogs.size() * sizeof(Dog));

	for (const Dog& dog : dogs) { // 꼭 const를 붙여햐됨
		cout << dog << endl;
	}

	save("메인.cpp");
}
