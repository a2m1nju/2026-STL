/*
2026년 1학기 STL 월56 화78
6/8 13주 2일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// 6.22 기말시험 -> 셋 오퍼레이션?? 뭐 공통단어 찾기? 
// STL Algorithms
// 1. Non - Modifying Sequence Operations
// 2. Modifying Sequence Operations
// 3. Sorting and relatied Operations

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <thread>
#include <chrono>
#include <print>
#include "save.h"
#include "ZString.h"
using namespace std;
extern bool 관찰;

default_random_engine dre{ random_device{}() };
int main()
{
	save("메인.cpp");

	// 이번주 lotto 번호를 알려주자.
	ZString zs("--> The quick brown fox jumps over the lazy dog ");

	for (int i = 0; i < 10; ++i)
		cout << endl;

	while (true) {
		print("{:^80}", string{ zs.begin(), zs.end() });
		this_thread::sleep_for(200ms);
		cout << '\r';
		rotate(zs.begin(), zs.end() - 1, zs.end());
	}



}


