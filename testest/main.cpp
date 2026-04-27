#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <print>   // C++23 std::println 사용
#include "z.h"

int main() {
    // ==========================================================
    // [문제 1] 파일 읽기 및 컨테이너 저장
    // ==========================================================
    // 컨테이너: std::vector<ZString> 사용 (연속된 메모리 배치로 효율적임)
    std::vector<ZString> words;

    // 11만개 미만이 확실하므로 미리 메모리를 할당하여 제로 오버헤드 실현
    words.reserve(110000);

    std::ifstream in("시험.dat"); // text mode
    if (!in) return 1;

    ZString temp;
    while (in >> temp) { // 공백 구분 읽기
        // 이동 생성자를 사용하여 자원 복사 없이 효율적으로 저장
        words.push_back(std::move(temp));
    }

    std::println("1-3) 저장된 객체 수: {}개", words.size());
    if (!words.empty()) {
        std::print("1-4) 마지막 객체 정보: ");
        words.back().show(); // 마지막 객체 정보 출력
    }

    // ==========================================================
    // [문제 2] 평균 길이 계산 및 출력
    // ==========================================================
    double total_length = 0;
    // const 참조자를 사용하여 불필요한 복사 방지
    for (const auto& zs : words) {
        total_length += zs.size();
    }
    double average = words.empty() ? 0 : total_length / words.size();

    // 소수점 한 자리까지 자릿수 맞춤 출력
    std::println("2) 평균 길이: {:.1f}", average);


    // ==========================================================
    // [문제 3] 길이 기준 오름차순 정렬
    // ==========================================================
    size_t actual_compare_count = 0;

    // 람다를 사용하여 인라인 최적화 유도 (함수 포인터보다 빠름)
    std::sort(words.begin(), words.end(), [&](const ZString& a, const ZString& b) {
        actual_compare_count++;
        return a.size() < b.size(); // 길이 기준 오름차순
        });

    double n = static_cast<double>(words.size());
    std::println("3) 예상 비교 횟수(n log n): {:.0f}", n * std::log2(n));
    std::println("   실제 비교 함수 호출 횟수: {}", actual_compare_count);


    // ==========================================================
    // [문제 4] 사전 순서 오름차순 정렬
    // ==========================================================
    // 추가한 operator< 멤버 함수를 사용하여 사전 순서 정렬
    std::sort(words.begin(), words.end());

    if (!words.empty()) {
        std::print("4-3) 정렬 후 마지막 객체 정보: ");
        words.back().show(); // 최종 정렬 후 마지막 객체 출력
    }

    return 0;
}