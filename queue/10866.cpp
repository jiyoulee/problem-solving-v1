/*
 * Title: 덱 
 * Link: https://www.acmicpc.net/problem/10866
 */

#include <cstdio>
#include <deque>
#include <cstring>

using namespace std;

int N, tmp;
char cmd[11];
deque<int> dq;

int main(int argc, char** argv) {
    scanf("%d", &N);

    while (N--) {
        scanf("%s", cmd);

        if (!strcmp("push_front", cmd)) {
            scanf("%d", &tmp);
            dq.emplace_front(tmp);
        }
        else if (!strcmp("push_back", cmd)) {
            scanf("%d", &tmp);
            dq.emplace_back(tmp);
        }
        else if (!strcmp("pop_front", cmd)) {
            printf("%d\n", dq.empty() ? -1 : dq.front());
            if (!dq.empty()) {
                dq.pop_front();
            }
        }
        else if (!strcmp("pop_back", cmd)) {
            printf("%d\n", dq.empty() ? -1 : dq.back());
            if (!dq.empty()) {
                dq.pop_back();
            }
        }
        else if (!strcmp("size", cmd)) {
            printf("%d\n", dq.size());
        }
        else if (!strcmp("empty", cmd)) {
            printf("%d\n", dq.empty());
        }
        else if (!strcmp("front", cmd)) {
            printf("%d\n", dq.empty() ? -1 : dq.front());
        }
        else {
            printf("%d\n", dq.empty() ? -1 : dq.back());
        }
    }

    return 0;
}