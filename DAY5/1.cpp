/*
2026년 1학기 STL 월56 화78
3/17 3주 1일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// 많은 수의 자료 다루기 - FILE I/O

#include <iostream>
#include<fstream>
#include <random>
#include "save.h"
using namespace std;

default_random_engine dre;
uniform_int_distribution <int> uid{ numeric_limits<int>::min(), numeric_limits<int>::max() };

int main()
{
	// [문제] 랜덤 int값 천만개를 다음과 같이 "int 천만개.txt" 파일에 저장하였다.

	ofstream out{ "int천만개.txt" };
	for (int i = 0; i < 1000'0000; ++i) {    // 119,828,581 bytes
		out << uid(dre) << '\n'; // endl 이랑 속도가 다름 -> 훨씬 빠름 이게
	}

	save("메인.cpp");
}
