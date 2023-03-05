/*
 * Problem: 팰린드롬 만들기
 * Tags: string, brute-forcing
 * Link: https://www.acmicpc.net/problem/1254
 *
 * Author: jiyoulee
 * Solved: 2023-03-05
 */

#include <cstdio>
#include <cstring>

using namespace std;

constexpr int MAX_S = 50;

int answer;
char S[MAX_S + 1];

int main() {
    /*
     * Input.
     */
    scanf("%s", S);

    /*
     * Compute.
     */
    answer = strlen(S);

    for (int i = 0, endi = strlen(S) - 1; S[i]; ++i) {
        bool is_valid = true;

        for (int j = i, k = strlen(S) - 1; j < k; ++j, --k) {
            if (S[k] != S[j]) {
                is_valid = false;
                break;
            }
        }

        if (is_valid) {
            answer += i;
            break;
        }
    }

    /*
     * Output.
     */
    printf("%d", answer);

    return 0;
}