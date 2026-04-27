// STL의 동작을 잘 살펴보기 위한 std::string과 비슷한 class
// 26.04.13
#include <print>
#include <string>
#include <algorithm>
#include "z.h"

size_t ZString::gid{}; // 외부에서 초기화
bool 관찰{ false };

ZString::ZString()
	:id{ ++gid }
{
	if (관찰)
		special("생성");

}

ZString::~ZString()
{
	if (관찰) {
		special("소멸");
	}
}

ZString::ZString(const char* s) {
	len = strlen(s);
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), s, len);

	if (관찰)
		special("생성(*)");

}

size_t ZString::getlen() const
{
	return len;
}

size_t ZString::size() const
{
	return len;
}


void ZString::special(std::string 동작) const
{
	int num = 10;
	if (len < 10) {
		num = len;
	}
	std::string 글자{};
	for (int i = 0; i < num; ++i) {
		글자 += p[i];
	}

	std::println("[{:7}] {:8} - 객체:{:#014X}, 글자: {:#014X}, 개수: {:<6}, 내용:{} ",
		id, 동작, (long long)this, (long long)p.get(), len, 글자);
}


void ZString::show() const
{
	special("show");
}




ZString::ZString(const ZString& other)// noexcept // 26.04.20 move에서 예외를 던지지 않는다
	:id{ ++gid }
{
	len = other.len;
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), other.p.get(), len);

	if (관찰)
		special("복사생성");

}

ZString& ZString::operator=(const ZString& other)// noexcept // 26.04.20 move에서 예외를 던지지 않는다
{
	if (this == &other)
		return *this;

	len = other.len;
	p.reset();
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), other.p.get(), len);

	if (관찰)
		special("복사할당");
	return *this;
}

ZString::ZString(ZString&& other)
	:id{ ++gid }
{
	len = other.len;
	p.reset(other.p.release());

	other.len = 0;
	// 자기 자원이 이동된 other는 xvalue가 되고 이것을 사용하면 undifined behavior

	if (관찰)
		special("이동생성");

}

ZString& ZString::operator=(ZString&& other)
{
	if (this == &other)
		return *this;

	len = other.len;
	// 메모리 반환 잘 됏는지?
	p.reset(other.p.release());
	other.len = 0;

	if (관찰)
		special("이동할당");
	return *this;

}

std::ostream& operator<<(std::ostream& os, const ZString& zs) {
	for (int i = 0; i < zs.len; ++i) {
		os << *(zs.p.get() + i);
	}
	return os;
}

// 파일에서 읽어오려고 만듦 - 2026.04.13
std::istream& operator >> (std::istream& is, ZString& zs)
{
	std::string s;
	is >> s;
	zs.len = s.size();
	zs.p.reset();
	zs.p = std::make_unique<char[]>(s.size());
	memcpy(zs.p.get(), s.data(), zs.len);

	return is;

}

 // std::lexicographical_compare 사용 가능

bool ZString::operator<(const ZString& other) const {
	// 문자열의 실제 내용(p)을 비교하여 사전 순서 판단
	// 두 문자열의 길이를 고려하여 비교함
	size_t min_len = std::min(len, other.len);
	for (size_t i = 0; i < min_len; ++i) {
		if (p[i] != other.p[i]) return p[i] < other.p[i];
	}
	return len < other.len;
}