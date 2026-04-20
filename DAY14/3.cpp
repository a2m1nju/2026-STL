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
	//array<ZString, 5> a{ "1", "22", "333", "4444", "55555"};
	array<int, 5> a{ 1, 2, 3, 4, 5 };


	// at()
	while (true) {
		cout << "찾을 원소는? : ";
		int num;
		cin >> num;

		// 검사코드가 ㅈㄴ반복도디면 당연히 느려지겠죠
		// 속도에 방해되는걸 날려버리는게 좋음
		// 그래서 이런 코딩을 하지 않는게 좋음
		if (num > 0 or a.size() <= num) {
			cout << "다시입력" << endl;
		}
		else {
			cout << num << "번 - " << *(a.data() + sizeof(int) * num) << endl;
		}
		//cout << num << "번 - " << a[num] << endl;
		//cout << num << "번 - " << *(a.data() + sizeof(int) * num) << endl;
	}

	save("메인.cpp");
}

