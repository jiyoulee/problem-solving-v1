/*
 * Title: 팰린드롬?
 * Link: https://www.acmicpc.net/problem/10942
 */

#include <cstdio>

constexpr int MAX_N = 2000;

int N, M, S, E;
int A[1 + MAX_N];
bool is_palindrome[1 + MAX_N][1 + MAX_N];

int main(int argc, char** argv) {
    /*
     * Determine "palindromity" for all subsets.
     */
    scanf("%d", &N);
    scanf("%d", &A[1]);
    is_palindrome[1][1] = true;
    for (int i = 2; N >= i; ++i) {
        scanf("%d", &A[i]);

        is_palindrome[i][i] = true;
        if (A[i] == A[i - 1]) {
            is_palindrome[i - 1][i] = true;
        }
    }
    for (int k = 2; N > k; ++k) {
        for (int s = 1, e = s + k; N >= e; s++, e++) {
            if (A[s] == A[e] && is_palindrome[s + 1][e - 1]) {
                is_palindrome[s][e] = true;
            }
        }
    }

    /*
     * Get "palidromity" for specific subset.
     */
    scanf("%d", &M);
    while (M--) {
        scanf("%d%d", &S, &E);

        printf("%d\n", is_palindrome[S][E]);
    }

    return 0;
}