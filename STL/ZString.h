// STL의 동작을 잘 살펴보기 위한 std::string과 비슷한 class
// 26.04.13
#pragma once
#include <iostream>


// ZString은 표준 컨테이너의 동작을 흉내내고 있다.
class ZString {
//2026.05.26
// 표준 컨테이너라면 다음과 같은 타입을 제공해야겠다.
	//using iterator = ZString_Iterator;
	//using value_type = char;

public:
	ZString();
	~ZString();

	ZString(const char* s);

	// 복사
	ZString(const ZString&);
	ZString& operator=(const ZString&);


	// 이동 - c++11 부터 지원되는  move semantics
	ZString(ZString&&); //noexcept; // 26.04.20 move에서 예외를 던지지 않는다
	ZString& operator=(ZString&&);
	
	// 연산자 오버로딩 - 26.04.28
	bool operator==(const ZString& rhs) const;

	// 반복자 인터페이스 - 26.05.12
	char* begin() const;
	char* end() const;

	// 역방향 반복자 인터페이스 - 26.05.18
	char* rbegin() const;
	char* rend() const;
	
	// 인터페이스 - 나중에 삭제
	size_t getlen() const;

	// STL 컨테이너가 되려면 다음 함수정도는 제공해야 - 26.04.20
	size_t size() const;

	// 2026.05.11
	char* data() const;

	void show() const;


	void special(std::string) const;

	friend std::ostream& operator<<(std::ostream& os, const ZString& zs); //noexcept; // 26.04.20 move에서 예외를 던지지 않는다;

	// 파일에서 읽어오려고 만듦 - 2026.04.13
	friend std::istream& operator >> (std::istream& is, ZString& zs);

	// [문제 4] 사전 순서 정렬을 위한 비교 연산자 추가
	bool operator<(const ZString& other) const;


private:
	static size_t gid; // 고유번호를 부여하기 위한 값
	size_t id;  // 객체 고유번호 - 생성 시 유일한 값
	size_t len{}; // 관리하는 글자 개수
	std::unique_ptr<char[]>  p{};  // 글자가 저장된 메모리

};

class ZString_Iterator {
public:
	/*
// random_iterator 이면서 sort가 요구하는 동작만을 코딩
ZString_lterator(char* p) : p{ p } {}

ZString_lterator& operator++() {
	++p;
	return *this;
}

ZString_lterator& operator--() {
	--p;
	return *this;
}

ZString_lterator operator +(difference_type n) const {
	return p + n;
}

//char& operator*() {
//	return *p;
//}

// 2026.05.26
ZString_lterator operator -(difference_type n) const {
	return p - n;
}
*/
};

