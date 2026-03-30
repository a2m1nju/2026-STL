/*
2026년 1학기 STL 월56 화78
3/30 4주 2일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// CALLABLE TYPES 콜러블 타입 -> 실습 -> STL

#include <iostream>
#include <fstream>
#include <algorithm>
#include "save.h"
using namespace std;

char 소투대(char c) {
	return c = toupper(c);
}

int main()
{
	// [문제] "메인.cpp"의 소문자를 모두 대문자로 바꾼 "메인대문자.cpp"를 만들어라
	
	/*
	transform
	exchange
	swap
	*/



	ifstream in{ "메인.cpp" };
	if (not in) {
		cout << "문제잇음" << endl;
		return 111;
	}

	ofstream out{ "메인대문자.cpp" };

	// transform(뭐를, 뭘로, 어떻게);
	// transform(메인시작.메인끝, 메인대문자의시작으로, 함수의시작번지)
	// transform(istreambuf_iterator<char>{in}, istreambuf_iterator<char>{}, )
	transform(istreambuf_iterator<char>{in}, {}, ostreambuf_iterator<char>{out}, 소투대);
	

	save("메인.cpp");

}

