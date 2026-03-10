/*
2026년 1학기 STL 월56 화78
3/10 2주 1일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [오늘 할 부분]
//tmeplate

#include <iostream>
#include "save.h"
using namespace std;

// 템플릿 함수 선언
template <class T>
void change(T&, T&);

// 템플릿 함수 정의
template <class T>
void change(T& p, T& q) {
	T temp{ p };
	p = q;
	q = temp;
}

int main()
{
	double a, b;
	change(a, b);


	save("메인.cpp");
}

