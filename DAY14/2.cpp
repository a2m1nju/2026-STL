/*
2026년 1학기 STL 월56 화78
4/20 7주 2일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// STL 컨테이너 - containers are objects that store other objects
// 

#include <iostream>
#include <array>
#include "save.h"
#include "ZString.h"
using namespace std;
extern bool 관찰;

// ilerator로 a를 순회
// element access - at, opertator[], front, back, data
int main()
{
	array<ZString, 5> a{ "1", "22", "333", "4444", "55555" };
	a.begin()->show();
	a[0].show();
	a.front().show();
	a.data()->show();

	save("메인.cpp");
}

