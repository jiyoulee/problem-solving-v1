/*
 * Problem: 명령 프롬프트
 * Tags: implementation, string
 * Link: https://www.acmicpc.net/problem/1032
 *
 * Author: jiyoulee
 * Solved: 2023-03-09
 */

#include <cstdio>

using namespace std;

constexpr int MAX_N = 50;
constexpr int MAX_CHAR = 50;
constexpr char WILDCARD = '?';

char answer[MAX_CHAR + 1];
int N;

int main() {
    /*
     * Input.
     */
    scanf("%d", &N);

    /*
     * Compute.
     */
    scanf("%s", answer);

    for (char tmp[MAX_CHAR + 1]; --N; ) {
        scanf("%s", tmp);

        for (int i = 0; answer[i]; ++i) {
            if (WILDCARD != answer[i] && tmp[i] != answer[i]) {
                answer[i] = WILDCARD;
            }
        }
    }

    /*
     * Output.
     */
    printf("%s", answer);

    return 0;
}