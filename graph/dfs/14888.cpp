/*
 * Title: 연산자 끼워넣기
 * Link: https://www.acmicpc.net/problem/14888
 */

#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAX_N = 11;
constexpr int INF = 1987654321;
constexpr int MINUS_INF = -1987654321;

int max_answer = MINUS_INF, min_answer = INF;
int N;
int A[MAX_N];
int O[4];

void go(int index, int result) {
    /*
     * In the event an expression has been fully generated, update the maximum/minimum with the value of the expression.
     */
    if (N == index) {
        max_answer = max(max_answer, result);
        min_answer = min(min_answer, result);

        return;
    }

    /*
     * Otherwise, continue generating the expression by adding the next operator.
     */
    if (O[0]) {
        --O[0];
        go(index + 1, result + A[index]);
        ++O[0];
    }
    if (O[1]) {
        --O[1];
        go(index + 1, result - A[index]);
        ++O[1];
    }
    if (O[2]) {
        --O[2];
        go(index + 1, result * A[index]);
        ++O[2];
    }
    if (O[3]) {
        --O[3];
        go(index + 1, result / A[index]);
        ++O[3];
    }

    return;
}

int main(int argc, char** argv) {
    /*
     * Get input.
     */
    scanf("%d", &N);
    for (int i = 0; N > i; ++i) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; 4 > i; ++i) {
        scanf("%d", &O[i]);
    }

    /*
     * Review all possible permutations of operators.
     */
    go(1, A[0]);

    printf("%d\n%d", max_answer, min_answer);

    return 0;
}