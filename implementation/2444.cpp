/*
 * Title: 별 찍기 - 7 
 * Link: https://www.acmicpc.net/problem/2444
 */

#include <cstdio>

using namespace std;

int N;

int main(int argc, char** argv) {
    scanf("%d", &N);

    for (int i = 0; N > i; ++i) {
        for (int j = N - (i + 1); j; --j) {
            printf(" ");
        }
        for (int j = 2 * i  + 1; j; --j) {
            printf("*");
        }
        printf("\n");
    }
    for (int i = N - 1; i; --i) {
        for (int j = N - i; j; --j) {
            printf(" ");
        }
        for (int j = 2 * i - 1; j; --j) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}