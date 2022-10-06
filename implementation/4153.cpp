#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
    int N[3];
    
    while (scanf("%d%d%d", &N[0], &N[1], &N[2]), N[0]) {
        sort(N, N + 3);

        printf(N[2] * N[2] == N[0] * N[0] + N[1] * N[1] ? "right\n" : "wrong\n");
    }

    return 0;
}