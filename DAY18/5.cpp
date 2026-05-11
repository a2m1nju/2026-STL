/*
2026년 1학기 STL 월56 화78
5/11 10주 1일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// array<T,N> - 유일하게 컴파일 타임에 사이즈를 결정
// vector<T> - 
// 
// deque<T> - 백터와 리스트의 장점을 갖는 컨테이너

#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include <chrono>
#include "save.h"
#include "ZString.h"
using namespace std;
extern bool 관찰;

int main()
{
	deque<ZString> d{ "1","22","333", "4444" };

	for (int i = 0; i < d.size(); ++i) {
		d[i].show();
	}


	save("메인.cpp");
}




