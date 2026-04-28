// 26.04.28 - ZString.cpp
bool ZString::operator==(const ZString& rhs) const
{
	// 동등성(equality)과 상등성(equivalence)의 차이
	// id, len, p가 있는데 ==> 내가 관리하는 글자가 같으면 같은거다.

	/* 이런식으로 작성하면 안됨 -> STL 형식이 아님
	if (len != rhs.len) return false;

	for (int i = 0; i < len; ++i) {
		if (p[i] == rhs.p[i]) return false;
	}

	return true;
	*/

	return std::equal(p.get(), p.get() + len, rhs.p.get());


}