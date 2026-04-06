/*
2026년 1학기 STL 월56 화78
4/6 5주 2일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// function을 사용하여 모든 호출가능 타입을 표현할 수 있다

#include <iostream>
#include <array>
#include <algorithm>
#include "save.h"
using namespace std;

bool 정렬기준(int a, int b) {
	cout << "함수" << ' ';  // 10 * log 10
	return a < b;
}

class Dog {
public:
	bool operator()(int a, int b){
		cout << "Dog" << ' ';
		return a < b;
	}
};

int main()
{
	array<int, 10> a{ 8, 4, 2, 0, 1, 9, 7, 5, 6, 3 };

	// sort(a.begin(), a.end(), 정렬기준);

	/*
	sort(a.begin(), a.end(), [](int a, int b) {
		cout << "람다" << ' ';
		return a < b;
		});
	*/

	sort(a.begin(), a.end(), Dog{});


	for (int num : a) {
		cout << num << ' ';
	}
	cout << endl;




	save("메인.cpp");
	
}

