/*
 * Title: 퇴사
 * Link: https://www.acmicpc.net/problem/14501
 */

#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAX_N = 15;

int answer;
int N;
int T[MAX_N];
int P[MAX_N];

void go(int day, int revenue) {
    /*
     * In the event today is valid for consultation, schedule one.
     */
    if (N >= day + T[day]) {
        revenue += P[day];
    }

    /*
     * In the event no more days are valid, stop. We've found our permutation.
     * Then, update maximum revenue.
     */
    if (N <= day + T[day]) {
        answer = max(answer, revenue);
        return;
    }

    /*
     * Otherwise, continue on to the next valid day.
     */
    for (int i = day + T[day]; N > i; ++i) {
        go(i, revenue);
    }

    return;
}

int main(int argc, char** argv) {
    scanf("%d", &N);
    for (int i = 0; N > i; ++i) {
        scanf("%d%d", &T[i], &P[i]);
    }

    /*
     * Check all possible cases.
     */
    for (int i = 0; N > i; ++i) {
        go(i, 0);
    }

    printf("%d", answer);

    return 0;
}