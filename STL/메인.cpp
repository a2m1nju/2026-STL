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

// c++언어의 보증사항
// 프로그램이 정상 종료시 (return문, exit와는 다름) 스택에 생성된 지역객체를
// 반드시 소멸됨을 보장한다.

int main()
{
	int* p = new int{ 20260330 };

	cout << *p << endl;

	return 0; // 메모리 leakage, 고갈

	cout << "이 문장은 출력 안됨" << endl;

	save("메인.cpp");

	delete p;
}

// 리턴문으로 끝낼때 뭐 선언된 지역객체? p가 사라짐을 보장한다?
// 예외가 던져졌을때도 예외를 잘ㄹ 처리하면 지역에서 만든 객체는 반드시 지워짐을 보장함
