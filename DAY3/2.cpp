/*
2026년 1학기 STL 월56 화78
3/10 2주 1일
*/

// 컴파일 환경 - Release / x64
// vs 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /std:c++latest
//               - C/C++ 언어 - SDL 검사 - 아니오

// [오늘 할 부분]
//tmeplate

#include <iostream>
#include <algorithm>
#include "save.h"
using namespace std;

class Dog; // forward declaration

// 템플릿 함수의 선언 
// -> 소스코드를 찍어내기 위한 틀
/*
template <class 자료형, class 자료동생>
void change(자료형&, 자료동생&);
*/

template <class T>
// template < class 구간의 시작, class 구간끝 , class 함수>
void change(T&, T&);


void change(int& p, int& q) {
	int temp{ p };
	p = q;
	q = temp;
}

class Dog {
public:
	Dog() = default;
	Dog(int n) : num{ n } {}

private:
	int num;
	friend ostream& operator << (ostream& os, const Dog& dog) {
		return os << dog.num;
	}
};

void change(Dog& p, Dog& q) {
	Dog temp{ p };
	p = q;
	q = temp;
}

int main()
{
	{
		Dog a{ 1 }, b{ 2 };
		change(a, b);
		cout << a << ", " << b << endl;
	}

	{
		int a{ 1 }, b{ 2 };
		change(a, b);
		cout << a << ", " << b << endl;
	}

	save("메인.cpp");
}

