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
#include <filesystem>
#include "save.h"
using namespace std;

// [문제] 파일 "int천만개"에는 int값 천만개가 저장되어 있다.
// 파일은 binary 모드로 열었고 int 값은 stream의 write 함수를 사용하여 저장하였다.


int main()
{
	std::filesystem::file_size("int천만개") / sizeof(int) << endl;

	save("메인.cpp");
}
