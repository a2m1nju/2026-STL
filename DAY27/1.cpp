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
#include "save.h"
#include "ZString.h"
using namespace std;
extern bool 관찰;

int main()
{
	save("메인.cpp");

	// 1 , 2, 3, 4, -> 4, 7, 6, 1
	cout << std::hash<int>{}(1) % 8 << endl;
	cout << std::hash<int>{}(2) % 8 << endl;
	cout << std::hash<int>{}(3) % 8 << endl;
	cout << std::hash<int>{}(4) % 8 << endl;

	unordered_multiset<int, hash<int>> ums;

	// unordered_set의 메모리 구조
	while (true) {
		cout << endl;
		cout << "추가할 int? : ";
		int num;
		cin >> num;

		ums.insert(num);

		for (int i = 0; i < ums.bucket_count(); ++i) {
			print("[{: > 3}]", i);

			for (auto j = ums.begin(i); j != ums.end(i); ++j) {
				cout << " - " << *j;
			}
			cout << endl;
		}
	}

}


