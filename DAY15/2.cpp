/*
2026년 1학기 STL 월56 화78
4/27 8주 2일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// STL 컨테이너 - containers are objects that store other objects
// Sequence Container
// - array<T,N> - 유일하게 컴파일 타임에 size 결정 -> STACK, DATA
// - vector<T> - dynamic (size) array -> free-store에 data관리

#include <iostream>
#include <array>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <numeric>
#include "save.h"
#include "ZString.h"
using namespace std;
extern bool 관찰;

int main()
{
	save("메인.cpp");

	vector<ZString> v{ "1","22","333" };
	v.reserve(10); // 공간 늘리기

	cout << "v의 원소에 접근" << endl;
	v.push_back("4444");
	v.push_back("55555");  // -> 이렇게 사용하면 안됨 -> 매번 메모리를 움직여야하기 때문에
	v.push_back("666666"); // -> 해결방법 : 공간을 늘린다

	cout << "v의 원소에 접근" << endl;
	for (ZString& zs : v) { // 레퍼런스를 붙여서 원본을 사용하도록 함
		cout << zs << endl;
	}

}

