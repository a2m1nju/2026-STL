/*
2026년 1학기 STL 월56 화78
6/15 14주 2일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// 6.22 기말시험 -> 셋 오퍼레이션?? 뭐 공통단어 찾기? 
// STL Algorithms
// - partition
// - nth_element
// - partial_sort
// - sort
// - stable_sort

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <print>
#include <random>
#include <numeric>
#include <list>
#include "save.h"
#include "ZString.h"
using namespace std;
extern bool 관찰;

default_random_engine dre;

int main()
{
	save("메인.cpp");

	ifstream in{ "이상한 나라의 앨리스.txt" };
	if (not in)
		return 123455;

	vector<ZString> words;
	words.reserve{ 30'0000 };
	words.assign{ istream_iterator <ZString>{in}, {} };

	words.back().show();

	// 중복 객체 제거
	sort(words.begin(), words.end());
	words.erase(unique(words.begin(), words.end()));

	// 길이기준 오름차순으로 정렬
	ranges::stable_sort(words, {}, &ZString::size);


	for (const ZString& word : words)
		cout << word << endl;





}


