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
// 

#include <iostream>
#include <array>
#include "save.h"
#include "ZString.h"
using namespace std;
extern bool 관찰;

// ilerator로 a를 순회
// element access - at, opertator[], front, back, data
int main() 
{
	array<ZString, 5> a{ "1", "22", "333", "4444", "55555"};
	
	//array<ZString,5>::iterator i = a.begin(); -> 이걸 밑에처럼 씀
	auto i = a.begin();

	// i < a.end -> 이렇게 쓸 순 있지만 컨티구어스 상황일때만 가능한?
	for (auto i = a.rbegin(); i != a.rend(); ++i) { // 꼭 ++i로 써야함
		//cout << (*i).size() << endl;
		cout << (*i) << endl;

	}

	save("메인.cpp");
}

