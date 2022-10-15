/*
 * Title: 주사위 굴리기
 * Link: https://www.acmicpc.net/problem/23288
 */

#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

constexpr int MAX_N = 20;
constexpr int MAX_M = 20;
constexpr int dx[4] = {0, 1, 0, -1};
constexpr int dy[4] = {1, 0, -1, 0};

long long ans;
int N, M, K;
int x, y, dir = 0, tmp;
int die[7] = {0, 1, 2, 3, 4, 5, 6};
int grid[MAX_N][MAX_M];

int bfs(int x, int y) {
    int cnt = 1;
    queue<pair<int, int>> q;
    int visited[N][M];
    memset(visited, 0, sizeof(visited));

    q.emplace(x, y);
    visited[x][y] = true;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        if (0 <= (x - 1) && !visited[x - 1][y] && grid[x][y] == grid[x - 1][y]) {
            ++cnt;
            visited[x - 1][y] = true;
            q.emplace(x - 1, y);
        }

        if (N > (x + 1) && !visited[x + 1][y] && grid[x][y] == grid[x + 1][y]) {
            ++cnt;
            visited[x + 1][y] = true;
            q.emplace(x + 1, y);
        }

        if (0 <= (y - 1) && !visited[x][y - 1] && grid[x][y] == grid[x][y - 1]) {
            ++cnt;
            visited[x][y - 1] = true;
            q.emplace(x, y - 1);
        }

        if (M > (y + 1) && !visited[x][y + 1] && grid[x][y] == grid[x][y + 1]) {
            ++cnt;
            visited[x][y + 1] = true;
            q.emplace(x, y + 1);
        }
    }

    return cnt;
}

int main(int argc, char** argv) {
    /*
     * Get initial map status.
     */
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 0; N > i; ++i) {
        for (int j = 0; M > j; ++j) {
            scanf("%d", &grid[i][j]);
        }
    }

    /*
     * Execute commands.
     */
    while(K--) {
        /*
         * Roll the die.
         */
        x += dx[dir];
        y += dy[dir];
        if (0 > x || N <= x || 0 > y || M <= y) {
            x -= dx[dir];
            y -= dy[dir];

            dir += 2;
            dir %= 4;

            x += dx[dir];
            y += dy[dir];
        }

        switch(dir) {
            case 0:
                tmp = die[1];
                die[1] = die[4];
                die[4] = die[6];
                die[6] = die[3];
                die[3] = tmp;
                break;
            case 1:
                tmp = die[1];
                die[1] = die[2];
                die[2] = die[6];
                die[6] = die[5];
                die[5] = tmp;
                break;
            case 2:
                tmp = die[1];
                die[1] = die[3];
                die[3] = die[6];
                die[6] = die[4];
                die[4] = tmp;
                break;
            case 3:
                tmp = die[1];
                die[1] = die[5];
                die[5] = die[6];
                die[6] = die[2];
                die[2] = tmp;
                break;
            default:
                break;
        }

        /*
         * Update the total score.
         */
        ans += grid[x][y] * bfs(x, y);

        /*
         * Update direction to roll the die.
         */
        if (die[6] > grid[x][y]) {
            dir += 1;
            dir %= 4;
        }
        else if (die[6] < grid[x][y]) {
            dir += 3;
            dir %= 4;
        }
    }

    /*
     * Print out total score.
     */
    printf("%lld", ans);

    return 0;
}