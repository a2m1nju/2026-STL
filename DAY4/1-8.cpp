/*
2026년 1학기 STL 월56 화78
3/16 2주 2일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// 다음 시간 멤버 설명부터 다시

#include <iostream>
#include <random>
#include <print>
#include <algorithm>
#include <array>
#include "save.h"
using namespace std;

default_random_engine dre;
uniform_int_distribution uid{ 0, 9999 };

template<class T, int N>
class myArray {
public:
	size_t size() const {
		return N;
	}

	int& operator[](int idx) {
		return a[idx];
	}

	T* begin() {
		return &a[0];
	}

	T* end() {
		return &a[n];
	}
private:
	T a[N];
};

int main()
{
	myArray<int, 1000> a;

	for (int i = 0; i < a.size(); ++i) {
		a[i] = uid(dre);
	}

	for (int& num : a) {
		num = uid(dre);
	}

	for (int num : a) {
		print("{:8}", num);
	}

	auto [minPos, maxPos] = minmax_element(a.begin(), a.end());
	cout << endl;
	cout << "작은 값 : " << *minPos << " " << "큰 값 : " << *maxPos << endl;


	save("메인.cpp");
}

