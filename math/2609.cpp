#include <bits/stdc++.h>
using namespace std;

int A, B;

int gcd(int A, int B) {
	return B ? gcd(B, A % B) : A;						// Cf. return B ? gcd(A % B, B) : A; (X, infinite loop)
}

int main() {
	scanf("%d%d", &A, &B);
	
	printf("%d\n%d", gcd(A, B), A / gcd(A, B) * B);		// Cf. A * B / gcd(A, B) (X, overflow)
	
	return 0;
}