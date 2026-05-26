/*
2026년 1학기 STL 월56 화78
5/18 11주 1일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// 반복자란 무엇인가?
// 이걸 사용하는 이유는 ?
// 반복자의 종류를 구분한 이유?
// ZString이 표준 반복자를 제공하려면?
// STL 반복자 - Iterators are a generalization of pointers 
//				that allow a C++ program to work with different data structures in a uniform manner. 

#include <iostream>
#include <vector>
#include "save.h"
#include "ZString.h"
using namespace std;
extern bool 관찰;

template<class 반복자>
void f(반복자 iter)
{
	//cout << typeid(iter).name() << endl;
	// 클래스 타입으롤 부터 여분(iterator taits)의 정보를
	// itertator_category, value_type, pointer, referance
	cout << typeid(반복자::iterator_category).name() << endl;

}

int main()
{
	// 반복자의 종류를 구부하기

	f(ostream_iterator<int>{cout});


	save("메인.cpp");
}

