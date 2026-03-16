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
#include <array>
#include "save.h"
using namespace std;

default_random_engine dre;
uniform_int_distribution uid{ 0, 9999 };

int main()
{
	// [문제1] 랜덤 값을 갖는 int 1000개를 만들어라
	// int[1000] 이런 자료구조는 앞으론 쓰지 말 것
	// 대체할 수 있는 더 좋은 것이 있기 때문 - 시간/공간의 zero - overhead
	// array<T, N>

	// int a[1000]; 자료형은 int[n]인데, 이름 위치가 비정상
	array<int, 1000> a;

	for (int& num : a) {
		num = uid(dre);
	}

	for (int num : a) {
		print("{:8}", num);
	}

	// [문제] 가장 작은 값과 큰 값을 찾아 화면에 출력하라
	auto [작은값, 큰값] = minmax_element(begin(a), end(a));
	cout << endl;
	cout << "작은 값 : " << *작은값 << " " << "큰 값 : " << *큰값 << endl;


	save("메인.cpp");
}

