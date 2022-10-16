/*
 * Title: 요세푸스 문제 0
 * Link: https://www.acmicpc.net/problem/11866
 */

#include <cstdio>
#include <queue>

using namespace std;

constexpr int MAX_N = 1000;

int N, K;
queue<int> q;

int main(int argc, char** argv) {
    scanf("%d%d", &N, &K);

    for (int i = 1; N >= i; ++i) {
        q.emplace(i);
    }

    printf("<");
    while (1 != q.size()) {
        /*
         * Skip (K - 1) values.
         */
        for (int i = 1; K > i; ++i) {
            q.emplace(q.front());
            q.pop();
        }
        
        /*
         * Log (K)th value.
         */
        printf("%d, ", q.front());
        q.pop();
    }
    printf("%d>", q.front());

    return 0;
}