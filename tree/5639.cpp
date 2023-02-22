/*
 * Problem: Binary Search Tree
 * Tags: graph-theory, graph-traversal, tree, recursion
 * Link: https://www.acmicpc.net/problem/5639
 *
 * Author: jiyoulee
 * Solved: 2023-02-22
 */

#include <cstdio>

using namespace std;

constexpr int MAX_NODE = 10000;

int N;
int G[MAX_NODE + 10];

void traverse_postorder(int l, int r);

int main() {
    /*
     * Input.
     */
    for (int tmp; EOF != scanf("%d", &tmp); G[++N] = tmp) {}

    /*
     * Output.
     */
    traverse_postorder(1, N + 1);

    return 0;
}

void traverse_postorder(int l, int r) {
    if (r == l) {
        return;
    }

    int m = l + 1;

    while (r > m && G[l] > G[m]) {
        ++m;
    }

    traverse_postorder(l + 1, m);
    traverse_postorder(m, r);
    printf("%d\n",G[l]);

    return;
}