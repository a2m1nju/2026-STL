/*
2026년 1학기 STL 월56 화78
4/27 8주 2일
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
	// [문제] v에서 3을 제거하라. 
	// v.size() == 4 
	// 원소 {4, 1, 2, 4, 5}
	// v.capacity() == 5;
	// 원소제거는 std::remove()를 이용하면 된다.

	vector<int> v{ 1,2,3,4,5 };
	remove(v.begin(), v.end(), 3);


	save("메인.cpp");
}

