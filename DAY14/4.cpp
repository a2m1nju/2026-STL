/*
2026년 1학기 STL 월56 화78
4/20 7주 2일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// STL 컨테이너 - containers are objects that store other objects
// Sequence Container
// - array<T,N> - 유일하게 컴파일 타임에 size 결정 -> STACK, DATA
// - vector<T> - dynamic (size) array -> free-store에 data관리

#include <iostream>
#include <array>
#include <vector>
#include <fstream>
#include <algorithm>
#include "save.h"
#include "ZString.h"
using namespace std;
extern bool 관찰;

int main()
{
	save("메인.cpp");

	vector<ZString> v;
	// [문제] "메인.cpp"에 있는 모든 단어를 v에 저장하라
	ifstream in{ "메인.cpp" };
	if (not in) {
		return 0;
	}

	ZString zs;
	while (in >> zs) {
		v.push_back(zs);
	}

	sort(v.begin(), v.end(), [](const ZString& a, const ZString& b) {
		return a.size() < b.size();
		});

	for (const ZString& zs : v) {
		cout << zs << endl;
	}
}

