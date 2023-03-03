/*
 * Problem: Cubing
 * Tags: implementation, simulation
 * Link: https://www.acmicpc.net/problem/5373
 *
 * Author: jiyoulee
 * Solved: 2023-03-03
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>

#define CLOCKWISE '+'

using namespace std;

int T;
int N;
char init[8] = "awyrogb";
int dir, face;
char cmd[3];
char tmp;
char C[7][10];
unordered_map<char,int> m;
char face_order[7][6] = {{0, 0, 0, 0, 0, 0}, 
                         {0, 4, 5, 3, 6, 0},
                         {0, 4, 6, 3, 5, 0},
                         {0, 1, 5, 2, 6, 0},
                         {0, 1, 6, 2, 5, 0},
                         {0, 1, 4, 2, 3, 0},
                         {0, 1, 3, 2, 4, 0}};
char cube_order[8][6][3] = {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
                            {{1, 2, 3}, {7, 8, 9}, {9, 6, 3}, {3, 2, 1}, {1, 4, 7}, {1, 2, 3}},
                            {{1, 2, 3}, {3, 2, 1}, {9, 6, 3}, {7, 8, 9}, {1, 4, 7}, {1, 2, 3}},
                            {{1, 2, 3}, {7, 8, 9}, {7, 8, 9}, {3, 2, 1}, {7, 8, 9}, {1, 2, 3}},
                            {{1, 2, 3}, {3, 2, 1}, {3, 2, 1}, {7, 8, 9}, {3, 2, 1}, {1, 2, 3}},
                            {{1, 2, 3}, {1, 4, 7}, {1, 4, 7}, {1, 4, 7}, {1, 4, 7}, {1, 2, 3}},
                            {{1, 2, 3}, {9, 6, 3}, {9, 6, 3}, {9, 6, 3}, {9, 6, 3}, {1, 2, 3}}};

int main() {
    /*
     * Preset.
     */
    m['U'] = 1;
    m['D'] = 2;
    m['F'] = 3;
    m['B'] = 4;
    m['L'] = 5;
    m['R'] = 6;

    for (scanf("%d", &T); T--; ) {
        /*
         * Preset.
         */
        for (int i = 1; 6 >= i; ++i) {
            for (int j = 1; 9 >= j; ++j) {
                C[i][j] = init[i];
            }
        }

        /*
         * Input and Compute.
         */
        for (scanf("%d", &N); N--; ) {
            scanf("%s", cmd);

            face = m[cmd[0]];
            dir = (CLOCKWISE == cmd[1]);

            tmp = C[face][1]; C[face][1] = C[face][dir ? 7 : 3]; C[face][dir ? 7 : 3] = C[face][9]; C[face][9] = C[face][dir ? 3 : 7]; C[face][dir ? 3 : 7] = tmp;
            tmp = C[face][2]; C[face][2] = C[face][dir ? 4 : 6]; C[face][dir ? 4 : 6] = C[face][8]; C[face][8] = C[face][dir ? 6 : 4]; C[face][dir ? 6 : 4] = tmp;

            if (dir) {
                for (int i = 0; 4 >= i; ++i) {
                    for (int j = 0; 3 > j; ++j) {
                        C[face_order[face][i]][cube_order[face][i][j]] = C[face_order[face][i + 1]][cube_order[face][i + 1][j]];
                    }
                }
            }
            else {
                for (int i = 5; i; --i) {
                    for (int j = 0; 3 > j; ++j) {
                        C[face_order[face][i]][cube_order[face][i][j]] = C[face_order[face][i - 1]][cube_order[face][i - 1][j]];
                    }
                }
            }
        } 

        /*
         * Output.
         */
        for (int i = 0; 3 > i; ++i) {
            for (int j = 1; 3 >= j; ++j) {
                printf("%c", C[1][3 * i + j]);
            }
            printf("\n");
        }
    }

    return 0;
}