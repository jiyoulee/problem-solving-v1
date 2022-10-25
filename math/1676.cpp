/* 
 * Title: 팩토리얼 0의 개수
 * Link: https://www.acmicpc.net/problem/1676
 */

#include <cstdio>
#include <algorithm>

using namespace std;

int N, n;
int two_cnt, five_cnt;

int main(int argc, char** argv) {
    scanf("%d", &N);

    while (N) {
        n = N--;

        while (n && (0 == n % 2)) {
            ++two_cnt;
            n /= 2;
        }

        while (n && (0 == n % 5)) {
            ++five_cnt;
            n /= 5;
        }
    }
    
    printf("%d", min(two_cnt, five_cnt));

    return 0;
}