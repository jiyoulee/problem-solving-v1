#include <bits/stdc++.h>
using namespace std;

int n;
int a[101][101];
long long m[101][101]; // m[i] is the number of ways to reach tile (i,j) starting from tile (1,1).

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			scanf("%d",&a[i][j]);
		}
	}
	
	// Initialize.
	m[1][1]=1;
	
	// Update and memo (single option).
	for (int i=1;i<=n-1;i++) {
		for (int j=i;j>=1;j--) {
			if (m[j][i+1-j]*a[j][i+1-j]>0) {
				if (i+1-j+a[j][i+1-j]<=n) m[j][i+1-j+a[j][i+1-j]]+=m[j][i+1-j];
				if (j+a[j][i+1-j]<=n) m[j+a[j][i+1-j]][i+1-j]+=m[j][i+1-j];
			}
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=n;j>=i;j--) {
			if (m[j][n+i-j]*a[j][n+i-j]>0) {
				if (n+i-j+a[j][n+i-j]<=n) m[j][n+i-j+a[j][n+i-j]]+=m[j][n+i-j];
				if (j+a[j][n+i-j]<=n) m[j+a[j][n+i-j]][n+i-j]+=m[j][n+i-j];
			}
		}
	}
	
	printf("%lld",m[n][n]);
	
	return 0;
}