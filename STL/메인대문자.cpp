/*
2026년 1학기 STL 월56 화78
3/30 4주 2일
*/

// 컴파일 환경 - RELEASE / X64
// VS 버전 - 17.14.27
// 프로젝트 설정 - C++언어 표준 - /STD:C++LATEST
//               - C/C++ 언어 - SDL 검사 - 아니오

// [메모]
// CALLABLE TYPES 콜러블 타입 -> 실습 -> STL

#INCLUDE <IOSTREAM>
#INCLUDE <FSTREAM>
#INCLUDE "SAVE.H"
USING NAMESPACE STD;

INT MAIN()
{
	// [문제] "메인.CPP"의 소문자를 모두 대문자로 바꾼 "메인대문자.CPP"를 만들어라
	IFSTREAM IN{ "메인.CPP" };
	IF (NOT IN) {
		COUT << "문제잇음" << ENDL;
		RETURN 111;
	}

	OFSTREAM OUT{ "메인대문자.CPP" };
	CHAR CH;
	IN >> NOSKIPWS;
	
	WHILE (IN >> CH) {
		CH = TOUPPER(CH);
		OUT << CH;
	}



	SAVE("메인.CPP");

}

