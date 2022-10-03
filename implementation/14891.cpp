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
        switch(gear) {
            case 1:
                directions[1] = direction;
                if (gears[1][(heads[1] + 2) % 8] != gears[2][(heads[2] + 6) % 8]) {
                    directions[2] = -directions[1];
                }
                if (gears[2][(heads[2] + 2) % 8] != gears[3][(heads[3] + 6) % 8]) {
                    directions[3] = -directions[2];
                }
                if (gears[3][(heads[3] + 2) % 8] != gears[4][(heads[4] + 6) % 8]) {
                    directions[4] = -directions[3];
                }
                break;
            case 2:
                directions[2] = direction;
                if (gears[1][(heads[1] + 2) % 8] != gears[2][(heads[2] + 6) % 8]) {
                    directions[1] = -directions[2];
                }
                if (gears[2][(heads[2] + 2) % 8] != gears[3][(heads[3] + 6) % 8]) {
                    directions[3] = -directions[2];
                }
                if (gears[3][(heads[3] + 2) % 8] != gears[4][(heads[4] + 6) % 8]) {
                    directions[4] = -directions[3];
                }
                break;
            case 3:
                directions[3] = direction;
                if (gears[2][(heads[2] + 2) % 8] != gears[3][(heads[3] + 6) % 8]) {
                    directions[2] = -directions[3];
                }
                if (gears[1][(heads[1] + 2) % 8] != gears[2][(heads[2] + 6) % 8]) {
                    directions[1] = -directions[2];
                }
                if (gears[3][(heads[3] + 2) % 8] != gears[4][(heads[4] + 6) % 8]) {
                    directions[4] = -directions[3];
                }
                break;
            case 4:
                directions[4] = direction;
                if (gears[3][(heads[3] + 2) % 8] != gears[4][(heads[4] + 6) % 8]) {
                    directions[3] = -directions[4];
                }
                if (gears[2][(heads[2] + 2) % 8] != gears[3][(heads[3] + 6) % 8]) {
                    directions[2] = -directions[3];
                }
                if (gears[1][(heads[1] + 2) % 8] != gears[2][(heads[2] + 6) % 8]) {
                    directions[1] = -directions[2];
                }
                break;
            default:
                // do nothing
                break;
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