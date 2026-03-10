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
//#include "save.h"
using namespace std;

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

	save("1.cpp");
}

// 여기서 부터 설명 다시
// fname -> naming covention

void save(const std::string& fname)
{
	std::ifstream in{ fname }; // 물리적으로 저장된 파일은 fname에 들어있음 -> RAII패턴
	// fname의 관리를 in?이 해줌?
	// in.colse() -> 이렇게 절대 쓰면 안됨
	if (not in) { // ! -> 이걸로 쓰지 말기
		cout << fname << "- 열 수 없음" << '\n';
		exit(2026); // return 2026으로 ㄴㄴ
	}

	/*
	[한글자만]
	char c;
	in >> c;  고수준 입력 -> operator >> (in, c);
	cout << c;
	*/

	/*
	[전체글자]
	char c;
	while(in >> c) {
	   cout << c;
	}
	*/

	
	//[공백 포함]
	char c;
	in >> noskipws;
	while (in >> c) {
		cout << c;
	}
	

}