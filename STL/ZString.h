// STL의 동작을 잘 살펴보기 위한 std::string과 비슷한 class
// 26.04.13
#pragma once
#include <iostream>

class ZString {
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


	// 연산자 오버로딩
	
	// 인터페이스 - 나중에 삭제
	size_t getlen() const;

	// STL 컨테이너가 되려면 다음 함수정도는 제공해야
	size_t size() const;

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

