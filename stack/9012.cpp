/*
 * Title: Parenthesis
 * Link: https://www.acmicpc.net/problem/9012
 */

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int T;
string str;
vector<int> stack;

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while (T--) {
        cin >> str;
        for (auto& c : str) {
            if (')' == c && !stack.empty() && stack.back() == '(') {
                stack.pop_back();
            }
            else {
                stack.emplace_back(c);
            }
        }

        if (stack.empty()) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }

        stack.clear();
    }

    return 0;
}