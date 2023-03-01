/*
 * Problem: 드래곤 커브
 * Tags: implementation, simulation
 * Link: https://www.acmicpc.net/problem/15685
 *
 * Author: jiyoulee
 * Solved: 2023-03-01
 */

#include <cstdio>

using namespace std;

constexpr int MAX_X = 100;
constexpr int MAX_Y = 100;
constexpr int MAX_G = 10;
constexpr int LIM_D = 4;
constexpr int dx[4] = {0, -1, 0, 1};
constexpr int dy[4] = {1, 0, -1, 0};

int answer;
int N;
bool visited[1 + MAX_X][1 + MAX_Y];
char dir[1 << MAX_G + 10];

int main() {
    /*
     * Input.
     */
    scanf("%d", &N);

    /*
     * Compute.
     */
    for (int x, y, d, g, cnt; N--; ) {
        cnt = 0;

        scanf("%d%d%d%d", &y, &x, &d, &g);

        // Compute directions.
        for (dir[++cnt] = d; g--; ) {
            for (int i = cnt; i; --i) {
                dir[++cnt] = (dir[i] + 1) % LIM_D;
            }
        }

        // Compute respective coordinates.
        visited[x][y] = true;

        for (int i = 1; cnt >= i; ++i) {
            x += dx[dir[i]];
            y += dy[dir[i]];

            visited[x][y] = true;
        }   
    }

    /*
     * Output.
     */
    for (int i = 0; MAX_X > i; ++i) {
        for (int j = 0; MAX_Y> j; ++j) {
            if (visited[i][j] && visited[i][j + 1] && visited[i + 1][j] && visited[i + 1][j + 1]) {
                ++answer;
            }
        }
    }

    printf("%d", answer);

    return 0;
}