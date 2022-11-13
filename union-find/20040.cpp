/*
 * Title: 사이클 게임
 * Link: https://www.acmicpc.net/problem/20040
 */

#include <cstdio>
#include <cstring>

using namespace std;

constexpr int MAX_N = 500000;

int N, M, U, V;
int parent[MAX_N];

int find(int n) {
    if (-1 == parent[n]) {
        return n;
    }

    return parent[n] = find(parent[n]);
}

bool merge(int a, int b) {
    int A = find(a);
    int B = find(b);

    if (A != B) {
        parent[B] = A;
    }

    return A != B;
}

int main(int argc, char** argv) {
    scanf("%d%d", &N, &M);

    memset(parent, -1, sizeof(int) * N);
    for (int i = 1; M >= i; ++i) {
        scanf("%d%d", &U, &V);
        if (!merge(U, V)) {
            printf("%d", i);

            return 0;
        }
    }

    printf("0");

    return 0;
}