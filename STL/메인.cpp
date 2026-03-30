/*
2026년 1학기 STL 월56 화78
3/30 4주 2일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// 스마트 포인터 -> 콜러블 타입 -> 실습 -> STL

#include <iostream>
#include "save.h"
using namespace std;


int main()
{
	int* p;
	p = new int{ 20260330 };

	cout << *p << endl;

	save("메인.cpp");

	delete p;
}
