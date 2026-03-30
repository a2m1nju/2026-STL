/*
2026년 1학기 STL 월56 화78
3/10 2주 1일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [오늘 할 부분]

#include <iostream>
#include "save.h"
using namespace std;

class Dog; // forward declaration
void change(Dog&, Dog&);

class Dog {
public:
	Dog() = default;
	Dog(int n) : num{ n } {}

	/*
	이런 코드는 사용하면 안됨
	operator int() {
		return num;
	}
	*/

private:
	int num;
	friend ostream& operator << (ostream& os, const Dog& dog) {
		return os << dog.num;
	}
};

void change(Dog& p, Dog& q) {
	Dog temp{ p };
	p = q; // p.operator = (q)
	q = temp;
}

int main()
{
	// [문제 2] 의도대로 실행되게 하자
	{
		Dog a{ 1 }, b{ 2 }; // Dog a = 1, b = 2; -> 이렇게 쓰면 안됨
		change(a, b);
		cout << a << ", " << b << endl;

	}

	save("메인.cpp");
}

