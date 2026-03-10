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

// 템플릿 함수 선언과 정의를 분리할 수 없음
template <class T>
void change(T& p, T& q) {
	cout << "이 문장을 보면 컴파일러가 열일한줄 알아라" << endl;
	T temp{ p };
	p = q;
	q = temp;
}

// double에 대한 specialization
template <>
void change(double& p, double& q) {
	cout << "컴파일러가 찍어낸 코드" << endl;
	double temp{ p };
	p = q;
	q = temp;
}

int main()
{
	double a, b;
	change(a, b);  // 뭘 호출해야 하나? -> 함수호출우선순위 결정
	// change<double>(a, b); -> 원래 이렇게 명시하는데 알아서 유추하니깐 빼고 씀

	string s{ "2026년" }, t{ "3월 10일" };
	change(s, t);


	save("메인.cpp");
}

