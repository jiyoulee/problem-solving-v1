#include <bits/stdc++.h>
using namespace std;

int y;
int m[11]; // m[i] is the maximum asset possible at year i.

int main() {
	// Initialize.
	scanf("%d%d",m,&y);
	
	// Update and memo (multiple options).
	for (int i=1;i<=y;i++) {
		// Initialize.
		m[i]=(int)floor(1.05*m[i-1]);
		
		// Update and memo.
		if (0<=i-3) m[i]=max(m[i],(int)floor(1.20*m[i-3]));
		if (0<=i-5) m[i]=max(m[i],(int)floor(1.35*m[i-5]));
	}
	
	printf("%d",m[y]);
	
	return 0;
}