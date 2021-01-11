#include <bits/stdc++.h>
using namespace std;

int tmp, ans;
char a[100001];
vector<int> v;

int main() {
	scanf("%s", a);
	
	for (int i = 0; i < strlen(a); i++) {
		if ('(' == a[i]) {						// Either the hint of 1) a laser or 2) a stick is found.
			v.push_back(0);
		}
		else {									// Either 1) a laser or 2) an end of a stick is found. 
			if (0 == v.back()) {				// A laser is found.
				v.pop_back();
				v.push_back(1);					// * Count the laser.
			}
			else {								// An end of a stick is found.
				while (0 != v.back()) {			// * Count the number of lasers that cut the stick.
					tmp += v.back();
					v.pop_back();
				}
				ans += (tmp + 1);				// * Count the number of pieces the stick is cut into and add it to the answer.
				v.pop_back();
				v.push_back(tmp);				// * Leave the lasers in their place.
				tmp = 0;						// * (Reset global variable).
			}
		}
	}
	
	printf("%d", ans);
	
	return 0;
}