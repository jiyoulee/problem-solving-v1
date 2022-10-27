/*
 * Title: 나는야 포켓몬 마스터 이다솜
 * Link: https://www.acmicpc.net/problem/1620
 */

#include <iostream>
#include <unordered_map>
#include <cstring>

using namespace std;

int N, M;
string str;
unordered_map<int, string> id_to_name;
unordered_map<string, int> name_to_id;

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; N >= i; ++i) {
        cin >> str;
        id_to_name.emplace(i, str);
        name_to_id.emplace(str, i);
    }

    while (M--) {
        cin >> str;

        if (isdigit(str[0])) {
            cout << id_to_name[stoi(str)] << "\n";
        }
        else {
            cout << name_to_id[str] << "\n";
        }
    }

    return 0;
}