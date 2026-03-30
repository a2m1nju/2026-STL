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

// c++언어의 보증사항
// 프로그램이 정상 종료시 (return문, exit와는 다름) 스택에 생성된 지역객체를
// 반드시 소멸됨을 보장한다.

#include <iostream>
#include <memory>
#include "save.h"
using namespace std;

class Dog {
public:
	Dog() { cout << "생성" << endl; }
	~Dog() { cout << "소멸" << endl; }
};

int main()
{
	save("메인.cpp");
	
	// T* 는 raw - pointer이다. 앞으로 쓰지 말자 -> 아무것도 할 수 있는게 없어서?
	unique_ptr<Dog> p{ new Dog };  // RAII

	return 0;

	cout << "이 문장 출력 안됨" << endl;

	// delete p;
}

