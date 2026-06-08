/*
2026년 1학기 STL 월56 화78
6/8 13주 2일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// 6.22 기말시험
// STL unordered Associative Contaniner - 0(1)
// - unordered_set / - unordered_multiset
// - unordered_map / - unordered_multimap

#include <iostream>
#include <unordered_set>
#include <print>
#include <numeric>
#include<fstream>
#include "save.h"
#include "ZString.h"
using namespace std;
extern bool 관찰;

template <>
struct hash<ZString> {
	size_t operator()(const ZString& zs) const {
		return std::hash<std::string>{}(std::string(zs.begin(), zs.end()));
	}
};

int main()
{
	save("메인.cpp");

	ifstream in{ "메인.cpp" };
	if (not in) {
		return 123456;
	}

	unordered_multiset<ZString> ums{ "2026년", "6월", "8일", "월요일" };

	for (int i = 0; i < ums.bucket_count(); ++i) {
		print("[{: > 3}]", i);

		for (auto j = ums.begin(i); j != ums.end(i); ++j) {
			cout << " -> " << *j;
		}
		cout << endl;
	}

}


