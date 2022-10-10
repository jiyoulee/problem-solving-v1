/*
 * Title: 덩치
 * Link: https://www.acmicpc.net/problem/7568
 */

#include <cstdio>

using namespace std;

constexpr int MAX_N = 50;

struct Person {
    int x;
    int y;
} persons[MAX_N];

int N;
int cnt;

int main(int argc, char** argv) {
    scanf("%d", &N);
    for (int i = 0; N > i; ++i) {
        scanf("%d%d", &persons[i].x, &persons[i].y);
    }

    for (int i = 0; N > i; ++i) {
        cnt = 0;
        for (int j = 0; N > j; ++j) {
            if (persons[i].x < persons[j].x) {
                if (persons[i].y < persons[j].y) {
                    ++cnt;
                }
            }
        }
        printf("%d ", cnt + 1);
    }

    return 0;
}