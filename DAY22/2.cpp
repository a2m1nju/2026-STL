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



int main()
{
	// 반복자를 만들어 기능을 이해해 본다
	vector <char> v;
	v.reserve(10);
	auto p = v.begin();

	cout << "벡터 반복자 크기 : " << sizeof(v) << endl;

	*p = 'A';
	++p;
	*p = 'B';
	++p;
	*p = 'C';

	for (int i = 0; i < 10; ++i) {
		cout << v[i] << endl;
	}

	// 유니폼 하게.. 컨테이너가 달라지더라도 일관되게 코딩할 수 잇다..

	save("메인.cpp");
}

