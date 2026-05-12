/*
2026년 1학기 STL 월56 화78
5/12 10주 2일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// STL 컨테이너 - 
// array<T,N>		- 유일하게 컴파일 타임에 size를 결정 - STACK, DATA
// vector<T>		- 캐시 히트율이 높아 고속 데이터 처리에 유리
// list<T>			- 아무데서나 원소 추가/삭제 0(1)
// deque<T>			- vector와 list의 장점을 갖는 컨테이너
// forward_list<T>	- 네가 아무리 잘 코딩해도 나보다 효율적인 코드 못만든다
//					  It is intended that forward_list have zero space or
//					  time overhead relative to a hand-written C-sytle singly linked list
//					  Features that would conflict with that goal have been omitted 

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
	ZString zs{"The quick brown fox jumps over the lazy dog"};

	for (char c : zs) {
		cout << zs << endl;
	}


	save("메인.cpp");
}

