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
// 반복자를 이용한 C++ 프로그램(uniform manner) - STL 알고리즘 함수

#include <iostream>
#include <algorithm>
#include <vector>
#include "save.h"
#include "ZString.h"
using namespace std;
extern bool 관찰;

template<class 원본, class 복사본>
void my_copy(원본 beg, 원본 end, 복사본 out)
{
	while (beg != end) {
		*out++ = *beg++;
	}
}

int main()
{
	vector<int> s{ 1,2,3,4,5 };

	vector<int> v;
	v.reverse(s.size());

	my_copy(s.begin(), s.end(), v.begin());

	for (int num : v)
		cout << num << " ";
	cout << endl;

	save("메인.cpp");
}


