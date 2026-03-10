// 저장한 시간 

/*
2026년 1학기 STL 월56 화78
3/9 1주 2일
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
#include <chrono>
//#include "save.h"

void save(const std::string&); // 선언문

/*
사용하지 말아야할 자료형 -> 대체할 수 있음 -> zero-overhead
1. char* -> sting : 이런 자료형이 할 수 있는게 없음
char* name = '2026';   ->
2. T* -> smart pointer를 사용할 것
3. T[] -> 버퍼오버플로우 문제
*/

int main()
{
	std::cout << "26.03.09" << '\n';

	save("메인.cpp");
}

// 여기서 부터 설명 다시
// fname -> naming covention

void save(const std::string& fname)
{
	std::ifstream in{ fname }; // 물리적으로 저장된 파일은 fname에 들어있음 -> RAII패턴
	// fname의 관리를 in?이 해줌?
	// in.colse() -> 이렇게 절대 쓰면 안됨
	if (not in) { // ! -> 이걸로 쓰지 말기
		std::cout << fname << "- 열 수 없음" << '\n';
		exit(2026); // return 2026으로 ㄴㄴ
	}

	std::cout << fname << " 를 저장합니다." << '\n';

	std::ofstream out{ "2026년 1학기 STL 월56화78.txt", std::ios::app };
	// if 쓸 필요가 없음 -> 없으면 새로 만들고 있으면 덮어씀

	//chrono::system_clock::time_point::now = chrono:;system_clock::now() 
	// time epoch로 부터 1초마다 증가한 tick 수
	auto now = std::chrono::system_clock::now(); // 그리니치 천문대 시간

	using namespace std::chrono_literals;
	out << now + 9h << std::endl;

	out << std::endl << std::endl;
	out << "========================================" << std::endl;
	out << "저장한 시간 - " << now + 9h << std::endl;
	out << "========================================" << std::endl;
	out << std::endl;


	std::copy(std::istreambuf_iterator<char>{in}, {},
		std::ostream_iterator <char>{out});




}