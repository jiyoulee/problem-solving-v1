/*
 * Title: 카드2
 * Link: https://www.acmicpc.net/problem/2164
 */

#include <cstdio>

using namespace std;

constexpr int MAX_N = 500000;

int N;
int front, rear;
int queue[MAX_N];

int main(int argc, char** argv) {
    scanf("%d", &N);
    for (int i = 0, j = 1; N > i; ++i, ++j) {
        queue[i] = j;
    }

    front = 0; rear = N - 1;
    while (true) {
        front += 1;
        front %= N;

        if (front == rear) {
            break;
        }

        rear += 1;
        rear %= N;
        queue[rear] = queue[front];
        front += 1;
        front %= N;
    }

    printf("%d", queue[front]);

    return 0;
}