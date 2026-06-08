/*
2026년 1학기 STL 월56 화78
6/2 13주 1일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// 6.22 기말시험
//

#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include "save.h"
#include "ZString.h"
using namespace std;
extern bool 관찰;


int main()
{
	save("메인.cpp");

	// map 어디에 쓸 수 있나?

	// 게임회사와 히트작을 관리
	map<ZString, vector<ZString>> 회사와작품;

	회사와작품.insert(pair < ZString, vector<ZString>>("펄어비스", { "검은사막", "붉은사막" }));
	회사와작품["펄어비스"] = { "검은사막", "붉은사막" };
	회사와작품["펄어비스"].push_back("보라사막");

	for (const auto& [회사, 히트작] : 회사와작품) {
		cout << 회사;
		for (const ZString& 게임 : 히트작) {
			cout << "-" << 게임;
		}
		cout << endl;
	}




}


