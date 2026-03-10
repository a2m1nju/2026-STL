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
#include <string>
#include "save.h"
using namespace std;

template <class T>
T add(T a, T b) {
	return a + b;
}


int main()
{
	// [문제] template 함수 add를 한 개 만들어 실행되게 하라.
	cout << add(1, 2) << endl;

	cout << add("2026년"s, "3월 10일"s) << endl;
	// cout << add(string{ "2026년" }, string{ "3월 10일" }) << endl;


	save("메인.cpp");
}

/*
이렇게 답을 내면 0점임


*/