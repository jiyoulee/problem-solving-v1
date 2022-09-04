#include <iostream>
#include <cstdlib>

using namespace std;

constexpr int INF = 987654321;
constexpr int MAX_N = 10;
constexpr int MAX_M = 10;
constexpr int MAX_TRIAL_CNT = 10;
constexpr int DIRECTION_CNT = 4;
constexpr char RED_BALL = 'R';
constexpr char BLUE_BALL = 'B';
constexpr char HOLE = 'O';
constexpr char GROUND = '.';
constexpr int dx[4] = {-1, 1, 0, 0};
constexpr int dy[4] = {0, 0, -1, 1};

int N, M, RX, RY, BX, BY;
char grid[1 + MAX_N][1 + MAX_M];

int go(int rx, int ry, int bx, int by, int cnt) {
	int ret = INF;
	int tmp;

	/*
	 * Cut-off Condition #1:
	 * If the number of moves have exceeded 10, stop looking.
	 */
	if (MAX_TRIAL_CNT <= cnt) {
		return -1;
	}

	for (int i = 0; DIRECTION_CNT > i; ++i) {
		int nbx = bx;
		int nby = by;
		int nrx = rx;
		int nry = ry;
		bool is_out_red = false;
		bool is_out_blue = false;

		grid[rx][ry] = GROUND;
		do {
			nrx += dx[i];
			nry += dy[i];
			if (HOLE == grid[nrx][nry]) {
				is_out_red = true;
			}
		} while (GROUND == grid[nrx][nry]);
		if (!is_out_red) {
			nrx -= dx[i];
			nry -= dy[i];
			grid[nrx][nry] = RED_BALL;
		}

		grid[bx][by] = GROUND;
		do {
			nbx += dx[i];
			nby += dy[i];
			if (HOLE == grid[nbx][nby]) {
				is_out_blue = true;
			}
		} while (GROUND == grid[nbx][nby]);
		if (!is_out_blue) {
			nbx -= dx[i];
			nby -= dy[i];
			grid[nbx][nby] = BLUE_BALL;
		}

		if (!is_out_red) {
			grid[nrx][nry] = GROUND;
			do {
				nrx += dx[i];
				nry += dy[i];
				if (HOLE == grid[nrx][nry]) {
					is_out_red = true;
				}
			} while (GROUND == grid[nrx][nry]);
			if (!is_out_red) {
				nrx -= dx[i];
				nry -= dy[i];
				grid[nrx][nry] = RED_BALL;
			}
		}		

		if (is_out_blue) {
			if (!is_out_red) {
				grid[nrx][nry] = GROUND;
			}
			grid[bx][by] = BLUE_BALL;
			grid[rx][ry] = RED_BALL;

			continue;
		}
		else if (is_out_red) {
			grid[nbx][nby] = GROUND;
			grid[bx][by] = BLUE_BALL;
			grid[rx][ry] = RED_BALL;
		
			return (cnt + 1);
		}
		if (rx != nrx || ry != nry || bx != nbx || by != nby) {
			tmp = go(nrx, nry, nbx, nby, cnt + 1);
			if (-1 != tmp) {
				ret = min(ret, tmp);
			}

			grid[nbx][nby] = GROUND;
			grid[nrx][nry] = GROUND;
			grid[bx][by] = BLUE_BALL;
			grid[rx][ry] = RED_BALL;
		}
	}

	return (INF != ret ? ret : -1);
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	/*
	 * Get input.
	 */
	for (int i = 0; N > i; ++i) {
		for (int j = 0; M > j; ++j) {
			cin >> grid[i][j];

			switch (grid[i][j]) {
				case RED_BALL:
					RX = i;
					RY = j;
					break;
				case BLUE_BALL:
					BX = i;
					BY = j;
					break;
				default:
					// do nothing
					break;
			}
		}
	}

	/*
	 * Backtracking.
	 */
	cout << go(RX, RY, BX, BY, 0);

	return 0;
}