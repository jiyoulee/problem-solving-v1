/*
 * Title: 체스판 다시 칠하기
 * Link: https://www.acmicpc.net/problem/1018
 */

#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int INF = 987654321;
constexpr int MAX_N = 50;
constexpr int MAX_M = 50;
constexpr char pattern[2][8][8] = {{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W', \
									'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B', \
									'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W', \
									'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B', \
									'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W', \
									'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B', \
									'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W', \
									'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
								   {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B', \
								    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W', \
								    'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B', \
								    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W', \
								    'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B', \
								    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W', \
								    'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B', \
								    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}};

int ans[3] = {0, 0, INF};
int N, M;
char grid[MAX_N][MAX_M + 1];

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; N > i; ++i) {
		scanf("%s", grid[i]);
	}
	
	N -= 8;
	M -= 8;
	for (int i = 0; N >= i; ++i) {
		for (int j = 0; M >= j; ++j) {
			ans[1] = ans[0] = 0;
			
			for (int u = 0; 8 > u; ++u) {
				for (int v = 0; 8 > v; ++v) {
					if (pattern[0][u][v] != grid[i + u][j + v]) {
						++ans[0];
					}
					if (pattern[1][u][v] != grid[i + u][j + v]) {
						++ans[1];
					}
				}
			}
			
			ans[2] = min(ans[2], min(ans[0], ans[1]));
		}
	}
	
	printf("%d", ans[2]);
	
	return 0;
}