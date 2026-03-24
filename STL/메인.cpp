/*
2026년 1학기 STL 월56 화78
3/24 4주 1일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// 동적 메모리 할당(dynamic memory allocation)

#include <iostream>
#include <numeric>
#include "save.h"
using namespace std;

// [문제] 사용자가 입력한 수만큼 int를 저장할 메모리를 확보하라
// 1부터 시작하는 정수로 메모리를 채워라
// 합계를 화면에 출력하라

int main()
{
	int* p; // 스택에 생긴 객체

	while(true)
	{
		cout << "입력 : ";
		size_t num;
		cin >> num;
		
		try {
			p = new int[num]; // 프리스토어에 생긴 객체
		}

		catch (std::exception& e) {
			cout << "메모리 고갈" << e.what() << endl;
		}

		/*
		for (int i = 0; i < num; ++i) {
			p[i] = i + 1;
		}
		이걸 대체하는 코드 -> 틀릴 곳이 적어짐
		*/
		iota(p, p + num, 1);
		
		/*
		long long sum{};
		for (int i = 0; i < num; ++i) {
			sum += p[i];
		}
		*/
		// long long sum = accumulate(p, p + num, 0); 근데 accumulate <- 애가 감당을 못함
		// long long sum = accumulate(p, p + num, static_cast<long long> (0)); <- 이건 너무 긺
		long long sum = accumulate(p, p + num, 0LL);

		cout << "1부터 " << num << "까지의 합계 : " << sum << endl;
		delete[] p;
	}

	save("메인.cpp");
}
