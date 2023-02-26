/*
 * Problem: 바이러스
 * Tags: graph=theory, graph-traversal, breadth-first-search, depth-first-search
 * Link: https://www.acmicpc.net/problem/2606
 *
 * Author: jiyoulee
 * Solved: 2022-12-27
 */

#include <cstdio>
#include <vector>

using namespace std;

constexpr int MAX_N = 100;

int answer = -1;
int N, M;
vector<int> G[1 + MAX_N];
bool visited[1 + MAX_N];

void dfs(int n);

int main(int argc, char** argv) {
	/*
	 * Input.
	 */
	scanf("%d%d", &N, &M);

	for (int u, v; M--; ) {
		scanf("%d%d", &u, &v);

		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	/*
	 * Compute.
	 */
	dfs(1);

	/*
	 * Output.
	 */
	printf("%d", answer);

	return 0;
}

void dfs(int n) {
	visited[n] = true;
	++answer;

	for (auto& c : G[n]) {
		if (!visited[c]) {
			dfs(c);
		}
	}

	return;
}