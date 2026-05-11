/*
2026년 1학기 STL 월56 화78
5/11 10주 1일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]

#include <iostream>
#include <array>
#include <vector>
#include <fstream>
#include <list>
#include "save.h"
#include "ZString.h"
using namespace std;
extern bool 관찰;

int main()
{
	ifstream in{ "2026년 1학기 STL 월56화78.txt" };

	if (not in) {
		cout << "error" << endl;
		return 1234;
	}

	list <ZString> words{ istream_iterator<ZString>{in},{} };

	cout << "정렬하는 중" << endl;
	words.sort([](const ZString& a, const ZString& b) -> bool {
		return lexicographical_compare(a.data(), a.data() + a.size(), b.data(), b.data() + b.size());
		});
	cout << endl;

	for (const ZString& Zs : words) {
		cout << Zs << endl;
	}

	cout << "단어의 수 : " << words.size() << endl;

	save("메인.cpp");
}

// 리스트 정렬시간 5186 us



