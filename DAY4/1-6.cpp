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
	int a[1000];

	for (int& num : a) {
		num = uid(dre);
	}

	for (int num : a) {
		print("{:8}", num);
	}

	// [문제] 가장 작은 값과 큰 값을 찾아 화면에 출력하라
	pair<int*, int*> res = minmax_element(begin(a), end(a));
	// auto [작은 값, 큰 값] = minmax_element(begin(a), end(a));
	// systatic sugar인 structured binding을 사용하면 pair를 이렇게 쓸 수 있다
	cout << endl;
	cout << "작은 값 : " << *(res.first) << " " << "큰 값 : " << *(res.second) << endl;
	// cout << "작은 값 : " << 작은 값) << " " << "큰 값 : " << 큰 값 << endl;


	save("메인.cpp");
}

