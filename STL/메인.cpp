/*
2026년 1학기 STL 월56 화78
6/15 14주 2일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// 6.22 기말시험 -> 셋 오퍼레이션?? 뭐 공통단어 찾기? 
// STL Algorithms
// - partition
// - nth_element
// - partial_sort
// - sort
// - stable_sort

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <print>
#include <random>
#include <numeric>
#include "save.h"
#include "ZString.h"
using namespace std;
extern bool 관찰;

default_random_engine dre;

int main()
{
	save("메인.cpp");

	// 1부터 100까지 숫자를 준비한다.
	vector<int> v(100);
	ranges::iota(v, 1);

	ranges::shuffle(v, dre);

	// [문제] 전체 정렬
	sort(v.begin(), v.end());

	for (auto i = v.begin(); i < v.end(); ++i)
		print("{:4}", *i);
	cout << endl;



}


