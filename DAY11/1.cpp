/*
2026년 1학기 STL 월56 화78
4/7 6주 1일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// 중간고사 4월 21일

#include <iostream>
#include <array>
#include <fstream>
#include <ranges>
#include "save.h"
using namespace std;


class Dog {
private:
	string name;    // [1, 16]
	int id;         // [0, 999'9999]

	friend ostream& operator<<(ostream& os, const Dog& dog) {
		print(os, "[{:7}] - {}", dog.id, dog.name);
		//print(os, "[{:7}]", dog.id);
		return os;
	}
};

// [문제] 다운받은 "Dog10만마리"에는 class Dog객체 10만개가 저장되어 있다.
// 바이너리 모드로 저장하여 정확하게 4MB이다.
// 메모리로 모두 읽어와라.
// 앞에서 100개 출력하여 확인하라.

array<Dog, 10'0000> dogs;

int main()
{
	ifstream in{ "Dog10만마리", ios::binary };
	if (not in) {
		cout << "error" << endl;
		return 111;
	}

	in.read((char*)dogs.data(), dogs.size() * sizeof(Dog));

	for (const Dog& dog : dogs | views::take(100)) {
		cout << dog << endl;
	}


	save("메인.cpp");
}

