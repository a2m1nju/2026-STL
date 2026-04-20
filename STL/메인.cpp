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
#include <string>
#include "save.h"
#include "ZString.h"
using namespace std;
extern bool 관찰;

int main() 
{
	save("메인.cpp");

	// [문제] 키보드에서 입력한 모든 단어를 저장하라
	// 입력의 끝은 OS마다 지정되어 있다 (컨트롤 + Z)
	// 오름차순 정렬하고 출력하라

	//vector<std::string> v;
	//vector<std::string> v{ 키보드시작,끝 };
	vector<std::string> v{ istream_iterator<string>{cin}, {} };

	/*
	string s;
	while (cin >> s) {
		v.push_back(s);
	}
	*/

	// 오름차순 정렬
	sort(v.begin(), v.end());

	for (auto i = v.rbegin(); i != v.rend(); ++i) {
		cout << *i << endl;
	}
	/*
	for (const string& s : v) {
		cout << s << endl;
	}
	*/
	

}

