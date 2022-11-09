/*
 * Title: Which is Greater?
 * Link: https://www.acmicpc.net/problem/4101
 */

#include <cstdio>

int A, B;

int main(int argc, char** argv) {
    while (true) {
        scanf("%d%d", &A, &B);
        
        if (!A) {
            break;
        }

        printf((A > B) ? "Yes\n" : "No\n");
    }

    return 0;
}