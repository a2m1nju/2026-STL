/*
2026년 1학기 STL 월56 화78
3/3 1주 1일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// 한 학기 강의를 자동 저장하는 save 함수를 만든다,

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
//#include "save.h"

void save(const std::string&); // 선언문

int main()
{
	std::cout << "26.03.03" << '\n';

	save("메인.cpp");
}

// 여기서 부터 설명 다시

void save(const std::string& fname)
{
	std::ifstream in{ fname };
	std::ofstream out{ "2026년 1학기 STL 월56화78", std::ios::app };
	std::copy(std::istreambuf_iterator<char>{in}, {},
		std::ostream_iterator); <char>{out});

}