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
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include "save.h"
#include "ZString.h"
using namespace std;
extern bool 관찰;


int main()
{
	ifstream in{ "이상한 나라의 앨리스.txt" };
	if (not in) {
		cout << "error" << endl;
		return 111;
	}

	vector<ZString> v;
	//copy(istream_iterator<ZString>{in}, {}, back_inserter(v));

	cout << "읽은 단어 수 : " << v.size() << endl;

	// [문제] 어떤 단어가 가장 많이 사용되었는지 알고싶다
	// 많이 사용된 단어부터 단어와 개수를 화면에 출력하시오
	map<ZString, size_t> 단어와개수;

	for (const ZString& zs : v) {
		++단어와개수[zs];
		//단어와개수.insert(pair<ZString, size_t>(zs, 단어와개수.count(zs) + 1));
	}

	for (const auto& [단어, 개수] : 단어와개수) {
		cout << 단어 << 개수 << endl;
	}


	for (const std::pair<ZString, size_t>& p : 단어와개수) {
		cout << p.first << "-" << p.second << endl;

	}

	cout << "개별 단어의 개수 : " << 단어와개수.size() << endl;

	//multimap<size_t, ZString> 개수와단어;
	//개수와단어.find(!);

	multimap<size_t, ZString, greater<size_t>> 개수와단어;
	for (const auto& [단어, 개수] : 단어와개수)
		개수와단어.insert(make_pair(개수, 단어));

	for (const auto& [개수, 단어] : 개수와단어)
		cout << 단어 << "\t -" << 개수 << endl;



	save("메인.cpp");
}


