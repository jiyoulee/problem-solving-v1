#include <bits/stdc++.h>
using namespace std;

int N, n, cnt, nv, nh, ans = 1;
int g[100][100];
int dv[4] = {0, 1, 0, -1};
int dh[4] = {1, 0, -1, 0};
bool key[100][100];
bool locked[101];

void dfs(int v, int h) {
	key[v][h] = true;
	
	for (int i = 0; i < 4; i++) {
		nv = v + dv[i];
		nh = h + dh[i];
		
		if (0 <= nv && N > nv && 0 <= nh && N > nh && !key[nv][nh] && g[nv][nh] > n) {
			dfs(nv, nh);
		}
	}
	
	return;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &g[i][j]);
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			n = g[i][j];
			
			if (locked[n]) { // The scenario of areas as high as n being flooded has already been considered.
				continue;
			}
			else {			 // The scenario of areas as high as n being flooded has yet to be considered.
				locked[n] = true;
				
				/*
				 * Under the given scenario, check each square for signs of flooding.
				 * If square has not yet been checked for flooding and is not flooded,
				 * 1. Check "nearby" squares for signs of flooding to find the full size of the non-flooded area.
				 * 2. Increase the non-flooded area count.
				 */
				for (int v = 0; v < N; v++) {
					for (int h = 0; h < N; h++) {
						if (!key[v][h] && g[v][h] > n) {
							dfs(v, h);
							cnt++;
						}
					}
				}
				
				// Update maximum non-flooded area count.
				ans = max(ans, cnt);
				
				// (Reset global variables.)
				fill(&key[0][0], &key[N - 1][N], false);
				cnt = 0;
			}
		}
	}
	
	printf("%d", ans);
	
	return 0;
}