#include <cstdio>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int MAX_N = 100;
constexpr int MAX_L = 100;
constexpr char LEFT = 'L';
constexpr char RIGHT = 'R';
constexpr int dx[4] = {0, -1, 0, 1};
constexpr int dy[4] = {1, 0, -1, 0};

struct Direction {
	char C;
	int X;
};

bool is_apple[MAX_N + 1][MAX_N + 1];
deque<pair<int, int>> coordinates;
Direction directions[MAX_L];
int answer;
int N, K, L, X, Y, C;
int nx, ny, k, l;

int main(int argc, char** argv) {
	/*
	 * Read input.
	 */
	scanf("%d%d", &N, &K);
	for (int i = 0; K > i; ++i) {
		scanf("%d%d", &X, &Y);
		is_apple[X][Y] = true;
	}
	scanf("%d", &L);
	for (int i = 0; L > i; ++i) {
		scanf("%d %c", &directions[i].X, &directions[i].C);
	}

	/*
	 * Get game duration.
	 */
	coordinates.emplace_front(1, 1);
	while (true) {
		/*
		 * Move snake head.
		 */
		nx = coordinates.front().first + dx[k];
		ny = coordinates.front().second + dy[k];
		++answer;

		/*
		 * If needed, terminate game.
		 */
		if (nx < 1 || nx > N || ny < 1 || ny > N) {
			break;
		}
		if (coordinates.end() != find(coordinates.begin(), coordinates.end(), make_pair(nx, ny))) {
			break;
		}

		/*
		 * If needed, move snake tail.
		 */
		coordinates.emplace_front(nx, ny);
		if (is_apple[nx][ny]) {
			is_apple[nx][ny] = false;	
		}
		else {
			coordinates.pop_back();
		}

		/*
		 * If needed, adjust direction.
		 */
		if (L > l && directions[l].X == answer) {
			if (LEFT == directions[l].C) {
				k = (k + 1) % 4;
			}
			else {
				k = (k + 3) % 4;
			}
			++l;
		}
	}

	printf("%d", answer);

	return 0;
}