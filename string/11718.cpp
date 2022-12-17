/*
 * Title: 그대로 출력하기
 * Link: https://www.acmicpc.net/problem/11718
 */

#include <iostream>
#include <cstring>

using namespace std;

string str;

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(getline(cin, str)) {
        cout << str << "\n";
    }

    return 0;
}