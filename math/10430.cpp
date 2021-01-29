#include <bits/stdc++.h>
using namespace std;


int A, B, C;

int main() {
	scanf("%d%d%d", &A, &B, &C);
	
	printf("%d\n%d\n", (A + B) % C, ((A % C) + (B % C)) % C);
	printf("%d\n%d\n", (A * B) % C, ((A % C) * (B % C)) % C);
	
	return 0;
}