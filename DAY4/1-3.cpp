/*
2026년 1학기 STL 월56 화78
3/16 2주 2일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// c++ 에서 template의 역할은 무엇인가? - Generic Programming 구현하는 핵심
// C++언어의 paradigm 
// 다음주 - 많은 수의 자료를 다루기

#include <iostream>
#include <random>
#include <print>
#include "save.h"
using namespace std;

default_random_engine dre;
uniform_int_distribution uid{ 0, 9999 };

int main()
{
	// [문제]  가장 큰 값을 찾아 출력해라
	// int[1000]; -> 이런 형식은 반칙?
	int a[1000];

	for (int& num : a) {
		num = uid(dre);
	}

	for (int num : a) {
		print("{:8}", num);
	}

	int maxVal{ numeric_limits<int>::min() };

	for (int num : a) {
		if (maxVal < num) {
			maxVal = num;
		}
	}

	cout << endl;
	cout << "가장 큰 값 : " << maxVal << endl;


	save("메인.cpp");
}

