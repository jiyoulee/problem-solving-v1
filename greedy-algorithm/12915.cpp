/*
 * Title: 대회 개최
 * Link: https://www.acmicpc.net/problem/12915
 */

#include <cstdio>
#include <algorithm>

using namespace std;

int E, EM, M, MH, H;
int tmp;

int main(int argc, char** argv) {
    scanf("%d%d%d%d%d", &E, &EM, &M, &MH, &H);

    /*
     * Distribute EM and MH problems.
     */
    while (EM && MH) {
        tmp = min(min(H, M), E);

        if (E == tmp) {
            ++E;
            --EM;
        }
        else if (H == tmp) {
            ++H;
            --MH;
        }
        else {
            ++M;

            if (EM > MH) {
                --EM;
            }
            else {
                --MH;
            }
        }
    }

    /*
     * Distribute remaining EM problems if any.
     */
    while (EM) {
        tmp = min(min(H, M), E);

        if (E == tmp) {
            ++E;
            --EM;
        }
        else if (M == tmp) {
            ++M;
            --EM;
        }
        else {
            break;
        }
    }

    /*
     * Distribute remaining MH problems if any.
     */
    while (MH) {
        tmp = min(min(H, M), E);

        if (H == tmp) {
            ++H;
            --MH;
        }
        else if (M == tmp) {
            ++M;
            --MH;
        }
        else {
            break;
        }
    }

    printf("%d", min(min(H, M), E));

    return 0;
}