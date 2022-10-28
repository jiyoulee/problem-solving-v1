/*
 * Title: 듣보잡
 * Link: https://www.acmicpc.net/problem/1764
 */

#include <iostream>
#include <cstring>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
string str;
unordered_set<string> uset;
vector<string> v;

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    while(N--) {
        cin >> str;

        uset.emplace(str);
    }

    while (M--) {
        cin >> str;

        if (uset.end() != uset.find(str)) {
            v.emplace_back(str);
        }
    }
    sort(v.begin(), v.end());
    
    cout << v.size() << "\n";
    for (auto& e : v) {
        cout << e << "\n";
    }

    return 0;
}