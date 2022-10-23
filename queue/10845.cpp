/*
 * Title: 큐
 * Link: https://www.acmicpc.net/problem/10845
 */

#include <iostream>
#include <cstring>

using namespace std;

constexpr int MAX_N = 10000;

int N;
char cmd[6];
int tmp;
int front = -1, rear = -1;
int queue[MAX_N];

int main(int argc, char** argv) {
    scanf("%d", &N);

    while(N--) {
        scanf("%s", cmd);

        if (!strcmp("push", cmd)) {
            scanf("%d", &tmp);

            queue[++rear] = tmp;
        }
        else if (!strcmp("pop", cmd)) {
            cout << ((front == rear) ? -1 : queue[++front]) << "\n";
        }
        else if (!strcmp("size", cmd)) {
            cout << (rear - front) << "\n";
        }
        else if (!strcmp("empty", cmd)) {
            cout << (0 == (rear - front)) << "\n";
        }
        else if (!strcmp("front", cmd)) {
            cout << ((front == rear) ? -1 : queue[front + 1]) << "\n";
        }
        else if (!strcmp("back", cmd)) {
            cout << ((front == rear) ? -1 : queue[rear]) << "\n";
        }
    }

    return 0;
}