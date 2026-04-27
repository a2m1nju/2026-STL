#include <iostream>
#include <fstream>
#include <vector>
#include "ZString.h" // 수업시간에 코딩한 ZString 클래스 헤더

using namespace std;

int main() {
    // 1. 컨테이너 생성 및 메모리 예약 (문제 1-1, 1-2 관련)
    // 데이터가 11만 개를 넘지 않는다는 조건이 있으므로 미리 reserve하여 
    // 메모리 재할당(Reallocation)에 따른 성능 저하를 방지합니다.
    vector<ZString> v;
    v.reserve(110000);

    // 2. 파일 스트림 열기
    ifstream fin("시험.dat");
    if (!fin.is_open()) {
        cout << "시험.dat 파일을 열 수 없습니다." << endl;
        return 1;
    }

    // 3. 파일에서 단어를 읽어 컨테이너에 저장 (문제 1-1 관련)
    ZString temp;
    // 파일의 끝(EOF)에 도달할 때까지 공백을 기준으로 읽어들입니다.
    while (fin >> temp) {
        v.push_back(temp); // 컨테이너의 끝에 순차적으로 추가
    }

    // 파일 닫기
    fin.close();

    // ---------------------------------------------------------
    // 아래는 문제 1-3과 1-4의 정답을 콘솔에서 확인하기 위한 코드입니다.
    // ---------------------------------------------------------

    // 1-3) 모두 몇 개의 ZString 객체를 저장하였는가?
    cout << "저장된 총 객체 수: " << v.size() << endl;

    // 1-4) 컨테이너에 저장한 마지막 객체의 정보를 ZString::show()를 호출하여 출력
    if (!v.empty()) {
        cout << "마지막 객체 정보: ";
        v.back().show(); // v[v.size() - 1].show(); 와 동일
    }

    return 0;
}