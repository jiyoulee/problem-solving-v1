/*
 * Title: Aaah!
 * Link: https://www.acmicpc.net/problem/4999
 */

#include <cstdio>
#include <cstring>

constexpr int MAX_STR_LENGTH = 1000;

char A[MAX_STR_LENGTH + 1];
char B[MAX_STR_LENGTH + 1];

int main(int argc, char** argv) {
    scanf("%s%s", A, B);

    if (strlen(B) <= strlen(A)) {
        printf("go");
    }
    else {
        printf("no");
    }

    return 0;
}