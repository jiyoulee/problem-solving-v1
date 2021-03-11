#include <bits/stdc++.h>
using namespace std;

int N, n, ans;

int main() {
	scanf("%d", &N);
	
	n = N;
	do {
		n = (n % 10) * 10 + (n / 10 + n % 10) % 10;
		ans++;
	} while (n != N);
	
	printf("%d", ans);
	
	return 0;
}