/*
2026년 1학기 STL 월56 화78
3/9 1주 2일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [오늘 할 부분]
// save 파일 분리
// template

#include <iostream>
#include "save.h"
using namespace std;

void change(int&, int&);

void change(int& p, int& q) {
	int temp{ p };
	p = q;
	q = temp;
	// 임시저장소에 값을 저장 -> 어쩌고 -> 값 복구
}

int main()
{
	// cout << "main - " << addressof(main) << endl;
	// cout << "save - " << addressof(save) << endl;

	// [문제 1] 의도대로 실행되게 하자
	// change 를 호출해보자 -> 2, 1로 출력되어야 함
	// change -> 함수 이외에 호출할 수 있는 타입?

	int a{ 1 }, b{ 2 };
	//cout <<"a - " << addressof(a) << endl;
	change(a, b);

	cout << a << ", " << b << endl;

	save("메인.cpp");
}

