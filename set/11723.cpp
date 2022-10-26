/*
 * Title: 집합
 * Link: https://www.acmicpc.net/problem/11723
 */

#include <cstdio>

using namespace std;

char cmd[7];
int M, tmp;
bool set[21];

int main(int argc, char** argv) {
    scanf("%d", &M);

    while (M--) {
        scanf("%s", cmd);

        switch (cmd[1]) {
            case 'd':
                scanf("%d", &tmp);
                set[tmp] = true;
                break;
            case 'e':
                scanf("%d", &tmp);
                set[tmp] = false;
                break;
            case 'h':
                scanf("%d", &tmp);
                printf("%d\n", set[tmp]);
                break;
            case 'o':
                scanf("%d", &tmp);
                set[tmp] ^= true;
                break;
            case 'l':
                for (int i = 1; 20 >= i; ++i) {
                    if (!set[i]) {
                        set[i] = true;
                    }
                }
                break;
            case 'm':
                for (int i = 1; 20 >= i; ++i) {
                    if (set[i]) {
                        set[i] = false;
                    }
                }
                break;
            default:
                // do nothing
                break;
        }
    }

    return 0;
}