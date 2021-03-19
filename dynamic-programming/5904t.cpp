#include <bits/stdc++.h>
using namespace std;

int N, i;
char a[4];
vector<int> v;

int main() {
	scanf("%d", &N);

	a[1]='m';
	a[2]='o';
	a[3]='o';

	v.push_back(3);
	while (v.back() < N) {
		v.push_back(2 * v[i++] + i + 3);
	}

	while (1) {
		if (N <= v[0]) {
			printf("%c",a[N]);
			return 0;
		}
		while (N < v[i]) {
			i--;
		}
		if (N == v[i] + 1) {
			printf("m");
			return 0;
		}
		if (N <= v[i] + i + 4) {
			printf("o");
			return 0;
		}
		
		N -= v[i] + i + 4;
	}

	return 0;
}