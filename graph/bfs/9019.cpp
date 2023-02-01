/*
 * Problem: DSLR
 * Tags: graph-theory, graph-traversal, breadth-first-search
 * Link: https://www.acmicpc.net/problem/9019
 *
 * Author: jiyoulee
 * Solved: 2023-02-01
 */

#include <iostream>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

constexpr int MAX_N = 9999;
constexpr int DIV = 10000;

int T, A, B;
int N;
string cmd;
queue<pair<int,string>> q;
bool visited[1 + MAX_N];

void process(int N, char c);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (cin >> T; T--; ) {
        /*
         * Input.
         */
        cin >> A >> B;

        /*
         * Compute.
         */
        for (visited[A] = true, q.emplace(A, ""); B != q.front().first; ) {
            N = q.front().first;
            cmd = q.front().second;

            q.pop();

            process((N << 1) % DIV, 'D');
            process((0 == N) ? MAX_N : (N - 1), 'S');
            process((N % 1000) * 10 + N / 1000, 'L');
            process((N % 10) * 1000 + N / 10, 'R');
        }

        /*
         * Output.
         */
        cout << q.front().second << "\n";

        /*
         * Reset.
         */
        q = queue<pair<int,string>>();
        memset(visited, false, sizeof(visited));
    }

    return 0;
}

void process(int N, char c) {
    if (!visited[N]) {
        visited[N] = true;
        cmd.push_back(c);
        q.emplace(N, cmd);
        cmd.pop_back();
    }

    return;
}