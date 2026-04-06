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
#include "save.h"
using namespace std;

default_random_engine dre;
uniform_int_distribution uid{ 0, 999'9999 };
uniform_int_distribution uidName{ 1, 150 };
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

private:
	string name;    // [1, 150]
	int id;         // [0, 999'9999]

	friend ostream& operator<<(ostream& os, const Dog& dog) {
		print(os, "[{:7}] - {}", dog.id, dog.name);
		return os;
	}
};

// [문제] Dog 객체 10만개를 메모리에 저장하라
// std::sort를 사용하여 id 기준 오름차순으로 정렬하라
// 필요하다면 Dog에 interface 멤버를 추가하라.
// 앞에서 1000개의 내용을 cout으로 출력하라

array<Dog, 10'0000> dogs;

int main() 
{
	cout << "정렬 시작" << endl;

	sort(dogs.begin(), dogs.end(), [](Dog a, Dog b) {
		return a.getid() < b.getid();
		});

	// 이렇게 하면 쓸때없는 복사생성자가 사용되서 0점임

	cout << "정렬 끝" << endl;

	save("메인.cpp");
	
}

