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
// 컨테이너 찾기 성능 비교
// 1. 벡터
// 2. 멀티셋
// 3. 언오더드 멀티셋
// 1000만개에서 10만개 찾기

#include <iostream>
#include <unordered_set>
#include <array>
#include <vector>
#include <set>
#include <random>
#include <algorithm>
#include <chrono>
#include "save.h"
#include "ZString.h"
using namespace std;
extern bool 관찰;

const size_t NUM{ 1000'0000 };
const size_t FNUM{ 1'0000 };
array <int, NUM> num;
array <int, FNUM>fnum;

default_random_engine dre;
uniform_int_distribution uid{ 1, 2000'0000 };

int main()
{
	save("메인.cpp");
	
	for (int& num : num)
		num = uid(dre);

	for (int& num : fnum)
		num = uid(dre);

	{// 벡터에서 찾기
		cout << endl;
		cout << "백터에서 찾는 중..." << endl;
		vector<int> v{ num.begin(), num.end() };

		size_t cnt{};

		auto start = chrono::high_resolution_clock::now();
		
		for (int num : fnum) {
			if (find(v.begin(), v.end(), num) != v.end())
				++cnt;
		}

		auto stop = chrono::high_resolution_clock::now();

		cout << FNUM << "중에 " << cnt << "개 찾음" << endl;
		cout << "걸린시간 : " << chrono::duration_cast<chrono::microseconds>(stop - start) << endl;
	}

	{// 정렬된 벡터에서 찾기
		cout << endl;
		vector<int> v{ num.begin(), num.end() };

		cout << "벡터 정렬하는 중 ..." << endl;
		sort(v.begin(), v.end());

		cout << "정렬된 벡터에서 찾는 중..." << endl;
		size_t cnt{};

		auto start = chrono::high_resolution_clock::now();

		for (int num : fnum) {
			if (binary_search(v.begin(), v.end(), num))
				++cnt;
		}

		auto stop = chrono::high_resolution_clock::now();

		cout << FNUM << "중에 " << cnt << "개 찾음" << endl;
		cout << "걸린시간 : " << chrono::duration_cast<chrono::microseconds>(stop - start) << endl;
	}

	{// 셋에서 찾기
		cout << endl;
		cout << "set에서 찾는 중..." << endl;
		set<int> s{ num.begin(), num.end() };

		size_t cnt{};

		auto start = chrono::high_resolution_clock::now();

		for (int num : fnum) {
			if (s.contains(num)) {
				++cnt;
			}
		}

		auto stop = chrono::high_resolution_clock::now();

		cout << FNUM << "중에 " << cnt << "개 찾음" << endl;
		cout << "걸린시간 : " << chrono::duration_cast<chrono::microseconds>(stop - start) << endl;
	}

	{// unordered_multiset에서 찾기
		cout << endl;
		cout << "unordered_multiset에서 찾는 중..." << endl;
		unordered_multiset<int> us{ num.begin(), num.end() };

		size_t cnt{};

		auto start = chrono::high_resolution_clock::now();

		for (int num : fnum) {
			if (us.contains(num)) {
				++cnt;
			}
		}

		auto stop = chrono::high_resolution_clock::now();

		cout << FNUM << "중에 " << cnt << "개 찾음" << endl;
		cout << "걸린시간 : " << chrono::duration_cast<chrono::microseconds>(stop - start) << endl;
	}


}


