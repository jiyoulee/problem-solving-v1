#include <cstdio>

constexpr int MAX_N = 20;
constexpr int MAX_M = 20;
constexpr int EAST = 1;
constexpr int WEST = 2;
constexpr int NORTH = 3;
constexpr int SOUTH = 4;
constexpr int dx[5] = {0, 0, 0, -1, 1};
constexpr int dy[5] = {0, 1, -1, 0, 0};

int N, M, x, y, K;
int cmd, nx, ny;
int grid[MAX_N][MAX_M];
int die[7];

int main(int argc, char** argv) {
	/*
	 * Get input.
	 */
	scanf("%d%d%d%d%d", &N, &M, &x, &y, &K);
	for (int i = 0; N > i; ++i) {
		for (int j = 0; M > j; ++j) {
			scanf("%d", &grid[i][j]);
		}
	}

	/*
	 * Process each command.
	 */
	while (K--) {
		scanf("%d", &cmd);

		/*
		 * Get coordinates of new location.
		 */
		nx = x + dx[cmd];
		ny = y + dy[cmd];

		/*
		 * In the event of out-of-bounds coordinates, discard command.
		 */
		if (0 > nx || N <= nx || 0 > ny || M <= ny) {
			continue;
		}

		/*
		 * Roll die to new location.
		 */
		x = nx;
		y = ny;
		die[0] = die[1];
		switch(cmd) {
			case EAST:
				die[1] = die[4];
				die[4] = die[6];
				die[6] = die[3];
				die[3] = die[0];
				break;
			case WEST:
				die[1] = die[3];
				die[3] = die[6];
				die[6] = die[4];
				die[4] = die[0];
				break;
			case NORTH:
				die[1] = die[5];
				die[5] = die[6];
				die[6] = die[2];
				die[2] = die[0];
				break;
			case SOUTH:
				die[1] = die[2];
				die[2] = die[6];
				die[6] = die[5];
				die[5] = die[0];
				break;
			default:
				break;
		}

		/*
		 * Print value on the top side of the die.
		 */
		printf("%d\n", die[1]);

		/*
		 * Adjust value on the bottom side of the die.
		 */
		if (0 == grid[x][y]) {
			grid[nx][ny] = die[6];
		}
		else {
			die[6] = grid[x][y];
			grid[x][y] = 0;
		}
	}

	return 0;
}