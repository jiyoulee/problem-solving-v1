#include <bits/stdc++.h>
using namespace std;

int N, ansa, ansb, xi, yi;
long long x, y, xy, x2, y2;	// Cf) When determining data type of variable, make sure to take arithmatic operation overflow into consideration.
long long rss=LLONG_MAX;	// Cf) Min/Max of a data type is of format "TYPE_MIN/MAX".

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d%d", &xi, &yi);
		x2 += xi * xi;
		y2 += yi * yi;
		xy += xi * yi;
		x += xi;
		y += yi;
	}
	
	// Do brute force search on permunation of a and b.
	for (int a = 1; a <= 100; a++) {
		for (int b = 1; b <= 100; b++) {
			if (rss > (y2) + (-2 * a * xy) + (-2 * b * y) + (a * a * x2) + (2 * a * b * x) + (N * b * b)) {
				rss > (y2) + (-2 * a * xy) + (-2 * b * y) + (a * a * x2) + (2 * a * b * x) + (N * b * b)
				ansa = a;
				ansb = b;
			}
		}
	}
	
	printf("%d %d", ansa, ansb);
	
	return 0;
}