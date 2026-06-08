/*
2026년 1학기 STL 월56 화78
6/2 13주 1일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// 6.22 기말시험
//

#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <random>
#include <print> 
#include "save.h"
#include "ZString.h"
using namespace std;
extern bool 관찰;

default_random_engine dre;
uniform_int_distribution uid{ 0, 10000 };



int main()
{
	save("메인.cpp");

	// map 어디에 쓸 수 있나?
	// 유니폼 분포는 유니폼한가?
	// 노멀분포를 화면에 출력

	map <size_t, size_t> 유니폼;
	for (int i = 0; i < 1'0000'0000; ++i) {
		int num = uid(dre);
		++유니폼[num / 200];

	}

	for (auto [구간, 개수] : 유니폼) {
		println("[{:2}] - {}", 구간, 개수);
	}





}


