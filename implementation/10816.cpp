/*
 * Title: 숫자 카드 2
 * Link: https://www.acmicpc.net/problem/10816
 */

#include <cstdio>

using namespace std;

constexpr int SCALAR = 10000000;

int N;
int tmp;
int n[SCALAR * 2 + 1];

int main(int argc, char** argv) {
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &tmp);
        ++n[tmp + SCALAR];
    }

    scanf("%d", &N);
    while (N--) {
        scanf("%d", &tmp);
        printf("%d ", n[tmp + SCALAR]);
    }
    
    return 0;
}