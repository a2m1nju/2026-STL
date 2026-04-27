/*
2026년 1학기 STL 월56 화78
4/27 8주 2일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]

#include <iostream>
#include <array>
#include <vector>
#include <fstream>
#include "save.h"
#include "ZString.h"
using namespace std;
extern bool 관찰;

int main()
{
	save("메인.cpp");

	// [문제] "메인.cpp"에 알파벳 소문자가 몇 개나 있는지다음과 같이 출력하라
	// a - 10,  b - 5, 중간생략 , z - 1

	// vector<int> v; -> 이건 가변? 이라서 쓰면 안된다?
	// size_t alpha[26];
	array<int, 26> alpha{};  // 메모리를 클리어 하고 시작

	ifstream in{ "메인.cpp" };
	if (not in) {
		cout << "error" << endl;
		return 123;
	}

	char c;
	while (in >> c) {
		if (islower(c)) {
			++alpha[c - 'a'];

		}
	}

	for (int i = 0; i < alpha.size(); ++i) {
		cout << static_cast<char>('a' + i) << "-" << alpha[i] << endl;
	}


}

