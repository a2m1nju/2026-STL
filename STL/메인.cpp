/*
2026년 1학기 STL 월56 화78
4/14 7주 1일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// STL 컨테이너 - containers are objects that store other objects


#include <iostream>
#include <array>
#include "save.h"
#include "ZString.h"
using namespace std;
extern bool 관찰;

// ilerator로 a를 순회
// element access - at, opertator[], front, back, data
int main() 
{
	array<ZString, 2> a{ "1", "333" }; // a -> container
	
	//array<array<ZString, 2>, 10> b;
	//vector<array<ZString, 2>> v;  -> 보통은 이렇게 씀

	a.fill("2026.04.14");

	for (const ZString& zs : a) {
		cout << zs << endl;
	}

	save("메인.cpp");
}

