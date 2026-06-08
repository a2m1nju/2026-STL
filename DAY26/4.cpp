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
#include "save.h"
#include "ZString.h"
using namespace std;
extern bool 관찰;


int main()
{
	save("메인.cpp");

	// [문제] 입력한 단어를 정렬한 후 출력하라.
	set<ZString> s{ istream_iterator<ZString>{cin}, {} };

	copy(s.begin(), s.end(), ostream_iterator < ZString > {cout, "\n"});

}


