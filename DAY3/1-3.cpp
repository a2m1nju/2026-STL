/*
2026년 1학기 STL 월56 화78
3/10 2주 1일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [오늘 할 부분]

#include <iostream>
#include <string>
#include "save.h"
using namespace std;

void change(string);
void change(int, int) {
	cout << "int 2개를 인자로" << endl;

}

int main()
{
	change(1, 2);
	change("12345");

	save("메인.cpp");
}

/*
name mangling 내용
*/