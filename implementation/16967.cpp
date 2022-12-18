/*
 * Title: 배열 복원하기
 * Link: https://www.acmicpc.net/problem/16967
 */

#include <cstdio>

using namespace std;

constexpr int MAX_H = 300;
constexpr int MAX_W = 300;

int a_H, a_W, b_H, b_W, X, Y;
int A[2 + 2 * MAX_H][2 + 2 * MAX_W];
int B[2 + 2 * MAX_H][2 + 2 * MAX_W];

int main(int argc, char** argv) {
    scanf("%d%d%d%d", &a_H, &a_W, &X, &Y);

    b_H = a_H + X;
    b_W = a_W + Y;

    for (int h = 1; b_H >= h; ++h) {
        for (int w = 1; b_W >= w; ++w) {
            scanf("%d", &B[h][w]);

            if ((X >= h && a_W >= w) || (a_H >= h && Y >= w)) {
                A[h][w] = B[h][w];
            }
            else if (X < h || Y < w) {
                A[h][w] = B[h][w] - A[h - X][w - Y];
            }
        }
    }
    
    for (int h = 1; a_H >= h; ++h) {
        for (int w = 1; a_W >= w; ++w) {
            printf("%d ", A[h][w]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}