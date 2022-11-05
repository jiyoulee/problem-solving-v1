/*
 * Title: 비밀번호 찾기
 * Link: https://www.acmicpc.net/problem/17219
 */

#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;

int N, M;
string key, value;
unordered_map<string, string> m;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	while (N--) {
		cin >> key >> value;
		m.emplace(key, value);
	}

	while (M--) {
		cin >> key;
		cout << m[key] << "\n";
	}

	return 0;
}