/*
2026년 1학기 STL 월56 화78
3/31 5주 1일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// CALLABLE TYPES 콜러블 타입 -> 실습 -> STL

#include <iostream>
#include <random>
#include <array>
#include <print>
#include <ranges>
#include <chrono>
#include "save.h"
using namespace std;
default_random_engine dre;
uniform_int_distribution uid{ 0, 999'9999 };

// [문제] 랜덤값을 갖는 int 1000만개를 메모리에 저장하라.
// qsort를 이용하여 오름차순 정렬하라.
// 정렬결과를 앞에서부터 1000개만 화면에 출력하라.

array<int, 1000'0000> a;

int 오름차순(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main()
{
	save("메인.cpp");

	for (int& num : a) {
		num = uid(dre);
	}

	// 시간측정시작
	auto start = chrono::high_resolution_clock::now();
	qsort(a.data(), a.size(), sizeof(array<int, 1000'0000>::value_type), 오름차순);
	auto stop = chrono::high_resolution_clock::now();

	auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);

	cout << "걸린 시간 : " << duration << endl;

}

