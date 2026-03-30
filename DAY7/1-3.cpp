/*
2026년 1학기 STL 월56 화78
3/24 4주 1일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// 스마트 포인터 -> 콜러블 타입 -> 실습 -> STL

#include <iostream>
#include <numeric>
#include <memory>
#include "save.h"
using namespace std;

// [문제] 사용자가 입력한 수만큼 int를 저장할 메모리를 확보하라
// 1부터 시작하는 정수로 메모리를 채워라
// 합계를 화면에 출력하라

int main()
{
	// int* p; -> 사용하지 말아야 함
	// C++11 에 익것의 완벽한 대체수단이 있기 때문에 -> smart_point
	unique_ptr<int[]> p;

	while (true)
	{
		cout << "입력 : ";
		size_t num;
		cin >> num;

		try {
			p.reset(new int[num]);
		}

		catch (std::exception& e) {
			cout << "메모리 고갈" << e.what() << endl;
		}

		iota(p.get(), p.get() + num, 1);

		long long sum = accumulate(p.get(), p.get() + num, 0LL);

		cout << "1부터 " << num << "까지의 합계 : " << sum << endl;
		delete[] p;
	}

	save("메인.cpp");
}
