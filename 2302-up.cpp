#include <bits/stdc++.h>
using namespace std;

int N,M,idx;
bool a[41];
int m[41]; // m[i] is the maximum number of seating tables possible that accomodates the person with ticket 1 up to (and including) the person with ticket i.

int main() {
	scanf("%d%d",&N,&M);
	for (int i=1;i<=M;i++) {scanf("%d",&idx);a[idx]=true;}
	
	// Create base.
	m[1]=1;
	if (!a[1]&&!a[2]) m[2]=2; else m[2]=1;
	
	// Update and memo (single option).
	for (int i=3;i<=N;i++) {
		if (a[i]||a[i-1]) m[i]=m[i-1];
		else m[i]=m[i-2]+m[i-1];
	}
	
	printf("%d",m[N]);
	
	return 0;
}