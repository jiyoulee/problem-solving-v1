/*
 * Title: 용액
 * Link: https://www.acmicpc.net/problem/2467
 */

#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

constexpr int MAX_N = 100000;
constexpr int INF = 2000000001;

int val, a, b;
int N;
int p, q;
int l, r, m;
int P[MAX_N];
int Q[MAX_N];

int main(int argc, char** argv) {
    /*
     * Get acids and alkalies.
     */
    scanf("%d", &N);
    for (int i = 0; N > i; ++i) {
        scanf("%d", &val);
        if (0 < val) {
            P[p++] = val;
        }
        else {
            Q[q++] = val;
        }
    }
    sort(P, P + p);
    sort(Q, Q + q, greater<int>());


    val = INF;
    /*
     * Review combinations of two acids.
     */
    if (1 < p && val > P[0] + P[1]) {
        val = P[0] + P[1];
        a = P[0];
        b = P[1];
    }
    /*
     * Review combinations of two alkalies.
     */
    if (1 < q && val > -(Q[0] + Q[1])) {
        val = -(Q[0] + Q[1]);
        a = Q[1];
        b = Q[0];
    }
    /*
     * Review combinations of one acid and one alkali.
     */
    for (int i = 0; p > i; ++i) {
        l = 0;
        r = q;
        
        while (l != r) {
            m = l + (r - l) / 2;
                if (P[i] <= -Q[m]) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }
            if (q > l) {
            if (val > abs(P[i] + Q[l])) {
                val = abs(P[i] + Q[l]);
                a = Q[l];
                b = P[i];
            }
        }
        if (0 < l) {
            if (val > abs(P[i] + Q[l - 1])) {
                val = abs(P[i] + Q[l - 1]);
                a = Q[l - 1];
                b = P[i];
            }
        }
    }

    printf("%d %d", a, b);

    return 0;
}