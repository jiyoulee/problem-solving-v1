#include <bits/stdc++.h>
using namespace std;

int n,ans;
int a[1001];
int m[1001]; // m[i] is the length of the longest increasing subsequence possible w/ elements a[1] to a[i].

int main() {
	// Get input.
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	// Set base.
	fill(m+1,m+1+n,1);
	
	// Recurse.
	for (int i=2;i<=n;i++) {
		for (int j=i-1;j>=1;j--) {
			if (a[j]<a[i]) m[i]=max(m[i],m[j]+1);
		}
	}
	
	// Finalize answer.
	for (int i=1;i<=n;i++) ans=max(ans,m[i]);
		
	printf("%d",ans);
	
	return 0;
}