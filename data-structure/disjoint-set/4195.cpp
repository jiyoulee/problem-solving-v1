#include <bits/stdc++.h>
using namespace std;

int T, F, en, ans;
string U, V;
map<string,int>::iterator u, v;
map<string, int> m;
int p[200001];
int c[200001];

int find(int u) {
	if (u == p[u]) {
		return u;
	}
	
	return p[u] = find(p[u]);
}

int merge(int u, int v) {									// merge() with set count maintanance.
	u = find(u);
	v = find(v);
	
	if (u != v) {
		p[v] = u;
		c[u] += c[v];
	}
	
	return c[u];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	
	while (T--) {
		cin >> F;
		
		while (F--) {
			cin >> U >> V;
			
			u = m.find(U);
			if (u == m.end()) {
				en += 1;
				m[U] = en;
				p[en] = en;
				c[en] = 1;
			}
			v = m.find(V);
			if (v == m.end()) {
				en += 1;
				m[V] = en;
				p[en] = en;
				c[en] = 1;
			}
			
			printf("%d\n", merge(find(m[U]), find(m[V])));
		}
		
		m.clear();
	}
	
	return 0;
}