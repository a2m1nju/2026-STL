/*
2026년 1학기 STL 월56 화78
4/13 6주 2일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// STL 컨테이너 - std::string과 유자한 ZString을 만들어서 컨테이너 본질에 접근

#include <iostream>
#include <array>
#include <algorithm>
#include <string>
#include<fstream>
#include "save.h"
#include "ZString.h"
using namespace std;
extern bool 관찰;

int main() 
{
	// [문제] "메인.cpp"에 있는 모든 단어를 ZString 객체로 읽어와라.
	// 단어란 공백으로 분리된 문자집합을 말한다.
	// 다음 문장이 문제없이 실행되도록 하자.

	ifstream in{ "메인.cpp" };
	if (not in) {
		cout << "문제잇음" << endl;
		return 123;
	}

	ZString s;
	while (in >> s) {
		cout << s << endl;
	}

	save("메인.cpp");
}

