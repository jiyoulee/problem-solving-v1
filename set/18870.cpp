/*
 * Title: 좌표 압축
 * Link: https://www.acmicpc.net/problem/18870
 */

#include <cstdio>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;

constexpr int MAX_N = 1000000;

int N;
int A[MAX_N];
set<int> s;
unordered_map<int, int> umap;

int main(int argc, char** argv) {
	scanf("%d", &N);

	for (int i = 0; N > i; ++i) {
		scanf("%d", &A[i]);
		s.emplace(A[i]);
	}

	int cnt = 0;
	for (auto& e : s) {
		umap[e] = cnt++;
	}

	for (int i = 0; N > i; ++i) {
		printf("%d ", umap[A[i]]);
	}

	return 0;
} 