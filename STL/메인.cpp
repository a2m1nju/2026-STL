/*
2026년 1학기 STL 월56 화78
3/23 3주 2일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// 많은 수의 자료 다루기 - FILE I/O - binary I/O

#include <iostream>
#include <random>
#include <fstream>
#include "save.h"
using namespace std;

default_random_engine dre;
uniform_int_distribution uid;

int main()
{
	// [문제] 랜덤 int값 1000개를 화면에 출력하라

	ofstream out("int천만개", ios::binary);
	// 114'826'203 - text mode
	// 40'000'000 - 메모리 그대로 저장하면 40MB

	int num;
	for (int i{}; i < 1000'0000; ++i) {
		// out << uid(dre) << '\n';
		num = uid(dre);
		out.write(reinterpret_cast<char*>(& num), sizeof(int));
	}

	save("메인.cpp");
}
