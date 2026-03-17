/*
2026년 1학기 STL 월56 화78
3/17 3주 1일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// 많은 수의 자료 다루기 - FILE I/O

#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include "save.h"
using namespace std;

array<int, 1000'0000> a;

int main()
{
	// [문제] "int천만개.txt" 파일에는 int값 천만개가 저장되어있다.
	// 천만개가 있다는 사실은 틀림없다 - 믿고 쓰자
	// 가장 작은 값을 찾아 출력하라.


	ifstream in{ "int천만개.txt" };
	if (not in) {
		cout << "파일이 업소용" << endl;
		return 111;
	}

	cout << "최소값 : " << *min_element(istream_iterator<int>{in}, {}) << endl;


	save("메인.cpp");
}
