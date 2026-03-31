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
// 1. 함수 -> 함수 포인터도 호출가능하다
// 2. lambda
// 3. () 연산자를 구현한 클래스 - 객체를 functor(함수객체)라 함
// 4. 멤버함수와 멤버함수 포인터

// function 클래스로 일관된 사용가능

#include <iostream>
#include "save.h"
using namespace std;

class Sakura {
public:
	void operator()() {
		cout << "안냥" << endl;
	};
};

int main()
{
	Sakura a;
	a();

	cout << typeid(a).name() << endl;


	save("메인.cpp");

}

// class `int __cdecl main(void)'::`2'::<lambda_1>
// class `int __cdecl main(void)'::`2'::Sakura
// 어디에서 만들어진 클래스인지 확인하려고 이렇게?

// class Sakura -> 전역

