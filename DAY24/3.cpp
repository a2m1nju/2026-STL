/*
2026년 1학기 STL 월56 화78
5/26 12주 1일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// 6.22 기말시험
// 반복자를 이용한 C++ 프로그램(uniform manner) - STL 알고리즘 함수

#include <iostream>
#include <algorithm>
#include <vector>
#include "save.h"
#include "ZString.h"
using namespace std;
extern bool 관찰;


int main()
{
	ZString zs{ "sphinx of black quartz 3 judge my 6 vow" };

	// [문제] zs에서 처음 나오는 짝수를 찾아라
	ZString::iterator p = find_if(zs.begin(), zs.end(), c);
	find_if(zs.begin(), zs.end(), [](char c) {
		if (isdigit(c)) {
			// num = atoi(c); -> 이건 너무 과한 코드
			int num = c - '0';

			if (num % 2 == 0) {
				return true;
			}
			return false;
		}
		});
	// 이미 숫자 판정을 했는데 또 짝수를 이렇게 판단한다고?

	if (p != zs.end()) {
		cout << "짝수 발견 -" << p - zs.begin() + 1 << endl;
	}
	else {
		cout << "짝수 없음 " << endl;
	}


	save("메인.cpp");
}


