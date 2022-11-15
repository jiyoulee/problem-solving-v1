/*
 * Title: 다각형의 면적
 * Link: https://www.acmicpc.net/problem/2166
 */

#include <cstdio>
#include <cmath>

using namespace std;

double ans;
int N;
double x, y, ox, oy, nx, ny;

int main(int argc, char** argv) {
    scanf("%d", &N);
    
    scanf("%lf%lf", &x, &y);
    ox = x;
    oy = y;
    while (--N) {
        scanf("%lf%lf", &nx, &ny);
        ans += x * ny;
        ans -= nx * y;
        x = nx;
        y = ny;
    }
    ans += x * oy;
    ans -= ox * y;

    printf("%0.1lf", abs(ans) / 2);
    return 0;
}