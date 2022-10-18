/*
 * Title: 좌표 정렬하기
 * Link: https://www.acmicpc.net/problem/11650
 */

#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAX_N = 100000;

struct Coordinate {
    int x;
    int y;
} coordinates[MAX_N];

int N;

bool compare(Coordinate a, Coordinate b);

int main(int argc, char** argv) {
    scanf("%d", &N);
    for (int i = 0; N > i; ++i) {
        scanf("%d%d", &coordinates[i].x, &coordinates[i].y);
    }

    sort(coordinates, coordinates + N, compare);

    for (int i = 0; N > i; ++i) {
        printf("%d %d\n", coordinates[i].x, coordinates[i].y);
    }

    return 0;
}


bool compare(Coordinate a, Coordinate b) {
    if (a.x == b.x) {
        return a.y < b.y;
    }

    return a.x < b.x;
}