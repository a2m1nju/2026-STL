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

int main()
{
	std::cout << "26.03.03" << '\n';

	//void save(const char[9]);
	//voud save(const char*);
	void save(const std::string&); // 선언문
	save("메인.cpp");

}