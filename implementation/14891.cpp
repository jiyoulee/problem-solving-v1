/*
 * Title: 톱니바퀴
 * Link: https://www.acmicpc.net/problem/14891
 */

#include <cstdio>
#include <cstring>

using namespace std;

int ans;
int K;
int gear, direction;
int gears[5][8];
int heads[5];
int directions[5];

int main(int argc, char** argv) {
    /* 
     * Get gear initial states.
     */
    for (int i = 1; 4 >= i; ++i) {
        for (int j = 0; 8 > j; ++j) {
            scanf("%1d", &gears[i][j]);
        }
    }

    /*
     * Execute gear rotation commands.
     */
    scanf("%d", &K);
    while (K--) {
        scanf("%d%d", &gear, &direction);

        /*
         * Determine rotation directions.
         */
        directions[gear] = direction;
        for (int i = gear, j = gear - 1; 0 < j; --i, --j) {
            if (gears[j][(heads[j] + 2) % 8] != gears[i][(heads[i] + 6) % 8]) {
                directions[j] = -directions[i]; 
            }
        }
        for (int i = gear, j = gear + 1; 4 >= j; ++i, ++j) {
            if (gears[i][(heads[i] + 2) % 8] != gears[j][(heads[j] + 6) % 8]) {
                directions[j] = -directions[i];
            }
        }

        /*
         * Rotate gears.
         */
        for (int i = 1; 4 >= i; ++i) {
            if (1 == directions[i]) {
                heads[i] += 7;
                heads[i] %= 8; 
            }
            else if (-1 == directions[i]) {
                heads[i] += 1;
                heads[i] %= 8;
            }
        }

        memset(directions, 0, sizeof(directions));
    }

    /*
     * Compute gear end states.
     */
    for (int i = 1; 4 >= i; ++i) {
        ans += gears[i][heads[i]] * (1 << (i - 1));
    }

    printf("%d", ans);

    return 0;
}