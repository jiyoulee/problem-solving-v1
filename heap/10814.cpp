/*
 * Title: 나이순 정렬
 * Link: https://www.acmicpc.net/problem/10814
 */

#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>

using namespace std;

int N;
int age, id = 1;
string name;
priority_queue<tuple<int, int, string>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; N > i; ++i) {
		cin >> age >> name;
		pq.emplace(-age, -id++, name);
	}
	
	while (!pq.empty()) {
		cout << -get<0>(pq.top()) << " " << get<2>(pq.top()) << "\n";
		pq.pop();
	}
	
	return 0;
}