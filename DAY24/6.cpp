/*
2026년 1학기 STL 월56 화78
5/26 12주 1일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// 6.22 기말시험
// 반복자를 이용한 C++ 프로그램(uniform manner) - STL 알고리즘 함수

#include <iostream>
#include <algorithm>
#include <vector>
#include "save.h"
#include "ZString.h"
using namespace std;
extern bool 관찰;

template<class 반복자, class 출력반복자>
void my_copy(반복자 b, 반복자 e, 출력반복자 out) {
	while (b != e) {
		*out = *b;
		++b;
		++out;
	}
}

int main()
{
	ZString zs{ "sphinx of black quartz 3 judge my 6 vow" };

	// 코드 설명은 다음주에
	my_copy(zs.begin(), zs.end(), ostream_iterator<ZString::value_type>{cout, " ### "});

	save("메인.cpp");
}


