/*
 * Title: 도키도키 간식드리미
 * Link: https://www.acmicpc.net/problem/12789
 */

#include <cstdio>
#include <vector>

using namespace std;

int N;
int next_num = 1;
vector<int> stack;

int main(int argc, char** argv) {
    scanf("%d", &N);

    for (int i = 0, cur_num; N > i; ++i) {
        scanf("%d", &cur_num);

        /*
         * Person at head of line is in order.
         */
        if (next_num == cur_num) {
            ++next_num;

            while (!stack.empty() && (next_num == stack.back())) {
                ++next_num;

                stack.pop_back();
            }
        }
        
        /*
         * Person at head of line is out of order.
         */
        else {
            stack.emplace_back(cur_num);
        }
    }

    if (N + 1 == next_num) {
        printf("Nice");
    }
    else {
        printf("Sad");
    }

    return 0;
}