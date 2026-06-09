/*
2026년 1학기 STL 월56 화78
6/9 14주 1일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// 6.22 기말시험 -> 셋 오퍼레이션?? 뭐 공통단어 찾기? 
// STL Algorithms
// 정렬 관련 알고리즘 - 복잡도 순서대로

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <print>
#include <random>
#include "save.h"
#include "ZString.h"
using namespace std;
extern bool 관찰;

default_random_engine dre{ random_device{}()};

int main()
{
	save("메인.cpp");

	ifstream in{ "이상한 나라의 앨리스.txt" };
	if (not in)
		return 12345;

	vector<ZString> v{ istream_iterator<ZString>{in},{} };
	cout << "모두 " << v.size() << "개의 단어를 읽었다" << endl;

	sort(v.begin(), v.end());
	auto newEnd = unique(v.begin(), v.end());
	v.erase(newEnd, v.end());
	cout << "중복을 제거한 단어수 : " << v.size() << endl; // 2949

	shuffle(v.begin(), v.end(), dre);

	//[문제] 길이가 홀수인것과 짝수인것으로 분리하라
	// 앞에는 홀수, 뒤에는 짝수
	// 홀수 앞에 짝수가 있으면 안된다.
	// 홀수와 짝수가 각각 몇 개인지 출력하라

	auto p = partition(v.begin(), v.end(), [](const ZString& a) {
		return a.size() % 2;
		});

	cout << "홀수 : "<< distance(v.begin(), p) << endl;
	for (auto i = v.begin(); i != p; ++i) {
		cout << *i << " ";
	}
	cout << endl;
	cout << endl;

	cout << "짝수 : "<< distance( p, v.end()) << endl;
	for (auto i = p; i != v.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;
}


