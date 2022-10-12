/*
 * Title: 단어 정렬
 * Link: https://www.acmicpc.net/problem/1181
 * Reference: https://www.acmicpc.net/source/46452539
 */

#include <iostream>
#include <set>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
set<pair<int, string>> s;
string word;

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    while (N--) {
        cin >> word;
        s.emplace(word.length(), word);
    }

    for (auto& e : s) {
        cout << e.second << "\n";
    }

    return 0;
}