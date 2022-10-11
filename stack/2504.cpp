#include <bits/stdc++.h>
using namespace std;

char a[31];
int tmp, ans;
vector<int> v;

int main() {
	// Get string.
	scanf("%s",a);
	
	// Check string format.
	// If string format is incorrect, print 0 and return.
	for (int i=0;i<strlen(a);i++) {
		switch(a[i]) {
			case '(': v.push_back(1); break;
			case '[': v.push_back(2); break;
			case ')': if (!v.empty()&&1==v.back()) v.pop_back(); else v.push_back(3); break;
			case ']': if (!v.empty()&&2==v.back()) v.pop_back(); else v.push_back(4); break;
			default: printf("something's wrong~");
		}
	}
	if (!v.empty()) {printf("0"); return 0;}
	
	// (Since string format is correct,) calculate string value. 
	for (int i=0;i<strlen(a);i++) {
		switch(a[i]) {
			case '(': v.push_back(-1); break;
			case '[': v.push_back(-2); break;
			case ')':
			if (-1==v.back()) {v.pop_back(); v.push_back(2);}
			else {tmp=0; while(0<v.back()) {tmp+=v.back(); v.pop_back();}
			v.pop_back(); v.push_back(tmp*2);}
			break;
			case ']':
			if (-2==v.back()) {v.pop_back(); v.push_back(3);}
			else {tmp=0; while(0<v.back()) {tmp+=v.back(); v.pop_back();}
			v.pop_back(); v.push_back(tmp*3);}
			break;
			default: printf("something's wrong~");
		}
	}
	while (!v.empty()) {ans+=v.back(); v.pop_back();}
	
	// Print string value.
	printf("%d",ans);
	
	return 0;
}