/*
2026년 1학기 STL 월56 화78
3/23 3주 2일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// 많은 수의 자료 다루기 - FILE I/O - binary I/O

#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include "save.h"
using namespace std;

int main()
{
	// [문제] int로 표현할 수 있는 값은 -2147483648 ~ 2147483647 까지 이다.
	// 모든 int 값을 하나도 빼지않고 한 개씩 파일에 txt로 기록하였다.
	// 값과 값은 빈칸 한 개로 구분하였다.
	// 이렇게 하면 int를 한 개 기록하는데 평균 몇 바이트가 필요한지 계산하라.





	save("메인.cpp");
}
