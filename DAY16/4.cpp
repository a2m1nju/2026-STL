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
#include "save.h"
#include "ZString.h"
using namespace std;
extern bool 관찰;

int main()
{
	// [문제] v에서 "22"를 제거하라. 

	vector<ZString> v{ "1", "22", "333" };
	remove(v.begin(), v.end(), "22");

	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << endl;
		//v[i].show();
	}

	save("메인.cpp");
}

