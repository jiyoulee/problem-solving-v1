/* 
 * Title: 별 찍기 - 6
 * Link: https://www.acmicpc.net/problem/2443
 */

#include <cstdio>

using namespace std;

int N;

int main(int argc, char** argv) {
    scanf("%d", &N);

    for (int i = 0; N > i; ++i) {
        for (int j = 0; i > j; ++j) {
            printf(" ");
        }
        for (int j = 2 * N - (2 * i + 1); j; --j) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}