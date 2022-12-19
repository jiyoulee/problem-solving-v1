/*
 * Title: 물 주기
 * Link: https://www.acmicpc.net/problem/23351
 */

#include <cstdio>

using namespace std;

int answer;
int N, K, A, B, P;

int main(int argc, char** argv) {
    scanf("%d%d%d%d", &N, &K, &A, &B);

    P = N / A;
    
    while (P <= K) {
        answer += P;
        K -= P;
        K += B;
    }
    answer += K;

    printf("%d", answer);

    return 0;
}