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
#include <ranges>
#include <algorithm>
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

	vector<ZString> words(istream_iterator<ZString>{in}, istream_iterator<ZString>{});

	sort(words.begin(), words.end(), [](const ZString& a, const ZString& b) -> bool {
		return lexicographical_compare(a.data(), a.data() + a.size(), b.data(), b.data() + b.size());
		});
	cout << endl;

	auto newEnd = ranges::unique(words);
	words.erase(newEnd.begin(), newEnd.end());

	cout << "중복을 제거하고 남은 단어의 수 : " << words.size() << endl;

	// [문제] 길이가 10인 단어만 화면에 출력하라
	copy_if(words.begin(), words.end(), ostream_iterator<ZString>(cout, "\n"),
		[](const ZString& zs) {
			return 10 == zs.size();
		});


	save("메인.cpp");
}




