#include <bits/stdc++.h>
using namespace std;

int l, cnt0, cnt1;
char a[501];

int main() {
	scanf("%s", a);
	
	l = strlen(a);
	for (int i = 0; i < l; i++) {
		if ('0' == a[i]) {
			cnt0++;
		}
		else {
			cnt1++;
		}
	}
	cnt0 /= 2;
	cnt1 /= 2;
	
	for (int i = l - 1; i >= 0 && 0 < cnt0 ; i--) {
		if ('0' == a[i]) {
			a[i] = '2';
			cnt0--;
		}
	}
	for (int i = 0; i < l && 0 < cnt1; i++) {
		if ('1' == a[i]) {
			a[i] = '3';
			cnt1--;
		}
	}
	
	for (int i = 0; i < l; i++) {
		if ('0' == a[i] || '1' == a[i]) {
			printf("%c", a[i]);
		}
	}
	
	return 0;
}