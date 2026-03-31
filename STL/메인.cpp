/*
2026년 1학기 STL 월56 화78
3/31 5주 1일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// CALLABLE TYPES 콜러블 타입
// 1. 함수
// 2. lambda

#include <iostream>
#include "save.h"
using namespace std;

void f() {
	cout << "호출 가능" << endl;
}

int main()
{
	void (*a)() = f; //  a는 함수 f를 가리키는 포인터

	a();



	save("메인.cpp");
	
}

