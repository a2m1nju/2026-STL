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
#include <deque>
#include <vector>
#include <list>
#include <chrono>
#include <algorithm>
#include <ranges>
#include <string>
#include <span>
#include "save.h"
#include "ZString.h"
using namespace std;
extern bool 관찰;



int main()
{
	// 반복자를 만들어 기능을 이해해 본다
	ostream_iterator<char> p{ cout, "@@@@\n" };
	//cout << "반복자의 크기 : " << sizeof(p) << endl;

	*p = 'A';  //p.operator*() = 'A';
	//++p; ->  이렇게 붙일 필요가 없음 -> 
	*p = 'B';
	*p = 'C';

	// 출력하는 반복자..
	// 출력이라는 것은 텔라그래프?를 모방?



	save("메인.cpp");
}

