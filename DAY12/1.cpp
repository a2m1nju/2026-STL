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
#include "save.h"
#include "ZString.h"
using namespace std;

int main()
{
	//관찰 = true;

	array<ZString, 5> zs{ "333", "1", "55555", "4444", "22" };

	관찰 = true;
	for (ZString& a : zs)
		cout << a << endl;
	//ZString a{ "2026년 4월 13일" };
	//ZString b = a; // 복사생성
	관찰 = false;





	save("메인.cpp");
}

