/*
 * Title: 음악프로그램
 * Link: https://www.acmicpc.net/problem/2623
 */

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

constexpr int MAX_N = 1000;

int N, M, K, U, V;
int cnt;
int answer[1 + MAX_N];
int indegree[1 + MAX_N];
vector<int> G[1 + MAX_N];
queue<int> q;

int main(int argc, char** argv) {
	scanf("%d%d", &N, &M);
	while (M--) {
		scanf("%d%d", &K, &U);
		while (--K) {
			scanf("%d", &V);

			++indegree[V];
			G[U].emplace_back(V);
			U = V;
		}
	}

	for (int i = 1; N >= i; ++i) {
		if (!indegree[i]) {
			q.emplace(i);
		}
	}
	for (cnt = 0; N > cnt && !q.empty(); ++cnt) {
		V = q.front();
		q.pop();

		answer[cnt] = V;
		for (auto& child : G[V]) {
			if (!--indegree[child]) {
				q.emplace(child);
			}
		}
	}

	if (N != cnt) {
		printf("0");
	}
	else {
		for (int i = 0; N > i; ++i) {
			printf("%d\n", answer[i]);
		}
	}

	return 0;
}