/*
2026년 1학기 STL 월56 화78
4/28 9주 1일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]

#include <iostream>
#include <array>
#include <vector>
#include <fstream>
#include <list>
#include "save.h"
#include "ZString.h"
using namespace std;
extern bool 관찰;

int main()
{
	//[문제] "22" 다음에 "333"을 추가하라

	vector<ZString> v{ "1", "22","4444","55555" };

	v.insert(v.begin() + 2, "333");
	// v.insert(++++v.begin(), "333"); -> 이렇게도 쓸 순 있지만 싸이코 같음
	// -> 이렇게 하는건 벡터한테 안좋음

	for (const ZString& zs : v) {
		cout << zs << endl;
	}







	save("메인.cpp");
}