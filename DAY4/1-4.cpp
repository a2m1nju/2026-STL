/*
2026년 1학기 STL 월56 화78
3/16 2주 2일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]

#include <iostream>
#include <random>
#include <print>
#include <algorithm>
#include "save.h"
using namespace std;

default_random_engine dre;
uniform_int_distribution uid{ 0, 9999 };

int main()
{
	// [문제]  가장 큰 값을 찾아 출력해라
	int a[1000];

	for (int& num : a) {
		num = uid(dre);
	}

	for (int num : a) {
		print("{:8}", num);
	}

	int* p = max_element(begin(a), end(a));
	//max_element(&a[0], &a[1000]); -> 숫자를 직접 적은 코드는 위험한 코드
	cout << endl;
	cout << "가장 큰 값 : " << *p << endl;



	save("메인.cpp");
}

