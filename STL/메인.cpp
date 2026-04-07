/*
2026년 1학기 STL 월56 화78
4/7 6주 1일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// STL 컨테이너 - std::string과 유자한 ZString을 만들어서 컨테이너 본질에 접근

#include <iostream>
#include <string>
#include "save.h"
using namespace std;

int main() 
{
	string s{ "2026." };
	s += "04.07";
	cout << s << endl;

	for (auto i{ s.begin() }; i < s.end(); ++i) {
		cout << *i << endl;
	}


	save("메인.cpp");
}

