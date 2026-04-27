/*
2026년 1학기 STL 월56 화78
4/27 8주 2일
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
#include <numeric>
#include "save.h"
#include "ZString.h"
using namespace std;
extern bool 관찰;

int main()
{
	save("메인.cpp");

	// 벡터가 메모리를 확장하는 순간을 관찰
	vector<int> v;
	while (true) {
		try {
			v.push_back(1);
		}
		catch (exception& e) {
			cout << "예외발생 : " << e.what() << endl;
			cout << "현재 원소 개수 : " << v.size() << endl;
			cout << "현재 용량 : " << v.capacity() << endl;
		}


	}

}

