#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAX_N = 500;
constexpr int MAX_M = 500;
constexpr int dx[19][3] = {
	{0, 0, 0},
	{1, 2, 3},
	{0, 1, 1},
	{1, 2, 2},
	{1, 2, 2},
	{0, 0, 1},
	{0, 0, 1},
	{0, 1, 2},
	{0, 1, 2},
	{0, 0, -1},
	{1, 1, 1},
	{1, 1, 2},
	{1, 1, 2},
	{0, -1, -1},
	{0, 1, 1},
	{0, 0, 1},
	{1, 1, 2},
	{0, 0, -1},
	{1, 1, 2}
};
constexpr int dy[19][3] = {
	{1, 2, 3},
	{0, 0, 0},
	{1, 0, 1},
	{0, 0, 1},
	{0, 0, -1},
	{1, 2, 0},
	{1, 2, 2},
	{1, 1, 1},
	{1, 0, 0},
	{1, 2, 2},
	{0, 1, 2},
	{0, 1, 1},
	{0, -1, -1},
	{1, 1, 2},
	{1, 1, 2},
	{1, 2, 1},
	{0, 1, 0},
	{1, 2, 1},
	{0, -1, 0}
};

int answer;
int N, M;
int grid[MAX_N + 6][MAX_M + 6];

int main(int arc, char** argv) {
	/*
	 * Get input.
	 */
	scanf("%d%d", &N, &M);
	N += 3;
	M += 3;
	for (int i = 3; N > i; ++i) {
		for (int j = 3; M > j; ++j) {
			scanf("%d", &grid[i][j]);
		}
	}

	/*
	 * Run a brute-force search on all possible tetrominoes.
	 */
	answer = -1;
	for (int i = 0; 19 > i; ++i) {
		for (int x = 3; N > x; ++x) {
			for (int y = 3; M > y; ++y) {
				answer = max(answer, grid[x][y] + grid[x + dx[i][0]][y + dy[i][0]] + grid[x + dx[i][1]][y + dy[i][1]] + grid[x + dx[i][2]][y + dy[i][2]]);
			}
		}
	}

	printf("%d", answer);

	return 0;
}