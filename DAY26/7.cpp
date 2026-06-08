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
normal_distribution nd{ 0.0, 0.05 };

int main()
{
	save("메인.cpp");

	// map 어디에 쓸 수 있나?
	// 유니폼 분포는 유니폼한가?
	// 노멀분포를 화면에 출력

	map <size_t, size_t> 노멀;
	for (int i = 0; i < 1'0000'0000; ++i) {
		double num = nd(dre);
		num = num * 5000 + 5000;
		if (num < 0)
			num = 0;
		if (10000 < num)
			num = 10000;

		++노멀[static_cast<int>(num) / 200];

	}

	for (auto [구간, 개수] : 노멀) {
		println("[{:2}] - {}", 구간, 개수);
	}





}


