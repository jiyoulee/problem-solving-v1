#include <bits/stdc++.h>
using namespace std;

int N, A, B, C;
int cal, price, ans;
int a[101];

int main() {
	scanf("%d%d%d%d", &N, &A, &B, &C);
	for (int i = 1; i <= N; i++) {
		scanf("%d", a + i);
	}
	
	/*
	 * 1. The calories per won of a pizza with x toppings is (C + sum(calories of ith topping)) / (A + B * x);
	 * 2. The maximum calories per won of a pizza with x toppings is the calories per won of the pizza with x greatest calories toppings.
	 */
	sort(a + 1, a + 1 + N);
	cal = C;
	price = A;
	ans = cal / price;
	for (int i = N; i >= 1; i--) { // i is number of toppings
		cal += a[i];
		price += B;
		ans = max(ans, cal / price);
	}
	
	printf("%d", ans);
	
	return 0;
}