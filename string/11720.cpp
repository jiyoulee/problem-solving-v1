#include <bits/stdc++.h>
using namespace std;

int N, ans;
char A[101];

int main() {
	scanf("%d\n", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%c", A + i);
	}
	
	for (int i = 1; i <= N; i++) {
		ans += A[i] - '0';
	}
	
	printf("%d", ans);
	
	return 0;
}