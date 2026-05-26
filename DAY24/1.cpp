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
// STL 반복자 - Iterators are a generalization of pointers 
//				that allow a C++ program to work with different data structures in a uniform manner. 

#include <iostream>
#include <algorithm>
#include <vector>
#include "save.h"
#include "ZString.h"
using namespace std;
extern bool 관찰;

int main()
{
	ZString zs{ "sphinx of black quartz judge my vow" };

	// [문제] 한 글자 입력받아 zs에 있는지 출력하라
	// 있다면 몇 번째 문자인지 출력, 없다면 없는문자라 출력

	cout << "찾을 글자는? : ";
	char c;
	cin >> c;

	find(zs.begin(), zs.end(), c);
	ZString::iterator p = find(zs.begin(), zs.end(), c);
	if (p != zs.end()) {
		cout << c << "-" << distance(zs.begin(), p) + 1 << "번 째 문자" << endl;
	}
	else {
		cout << "없는 문자" << endl;
	}



	save("메인.cpp");
}

