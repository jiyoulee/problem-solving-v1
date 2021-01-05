#include <bits/stdc++.h>
using namespace std;

int n,ans;
int a[1001];
int m[1001]; // m[i] is the length of the longest increasing subsequence possible w/ elements a[1] to a[i].

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	// Create base.
	m[1]=1;
	
	// Update and memo (multiple options).
	for (int i=2;i<=n;i++) {
		// Initialize.
		m[i]=1;
		
		// Update and memo.
		for (int j=i-1;j>=1;j--) {
			if (a[j]<a[i]) m[i]=max(m[i],m[j]+1);
		}
	}
	
	// Finalize.
	for (int i=1;i<=n;i++) ans=max(ans,m[i]);
		
	printf("%d",ans);
	
	return 0;
}