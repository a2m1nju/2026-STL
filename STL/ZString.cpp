// STL의 동작을 잘 살펴보기 위한 std::string과 비슷한 class
// 26.04.13
#include <print>
#include <string>
#include "ZString.h"

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


ZString::ZString(const ZString& other)
	:id{ ++gid }
{
	len = other.len;
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), other.p.get(), len);
		
}

ZString& ZString::operator=(const ZString& other) 
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


std::ostream& operator<<(std::ostream& os, const ZString& zs) {
	for (int i = 0; i < zs.len; ++i) {
		os << *(zs.p.get() + i);
	}
	return os;
}