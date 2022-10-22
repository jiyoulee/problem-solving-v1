/*
 * Title: 스택
 * Link: https://www.acmicpc.net/problem/10828
 */

#include <iostream>
#include <cstring>

using namespace std;

constexpr int MAX_N = 10000;

int N;
string cmd;
int arg;
int stack_size;
int stack[MAX_N + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	
	while(N--) {
		cin >> cmd;
		
		if ("push" == cmd) {
			cin >> arg;
			stack[++stack_size] = arg;
		}
		else if ("pop" == cmd) {
            cout << (stack_size ? stack[stack_size--] : -1) << "\n";
		}
		else if ("size" == cmd) {
			cout << stack_size << "\n";
		}
		else if ("empty" == cmd) {
			cout << !stack_size << "\n";
		}
		else if ("top" == cmd) {
            cout << (stack_size ? stack[stack_size] : -1) << "\n";
		}
	}
	
	return 0;
}