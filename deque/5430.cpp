/*
 * Problem: Integer List
 * Tags: implementation, data structures, string, parsing, deque
 * Link: https://www.acmicpc.net/problem/5430
 *
 * Author: jiyoulee
 * Solved: 2023-01-25
 */

#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAX_P = 100000;
constexpr int MAX_N = 100000;

int T, N;
char P[MAX_P + 1];
int X[1 + MAX_N];
int idx, val;
char tmp;
int b, e;
bool is_reversed, is_error;

int main() {
   scanf("%d", &T);

   while (T--) {
      /*
       * Input.
       */
      scanf("%s%d %c", P, &N, &tmp);

      while (true) {
        scanf(" %c", &tmp);

        if (']' == tmp) {
          break;
        }

        if (',' == tmp) {
          X[++idx] = val;
          val = 0;
        }
        else {
          val *= 10;
          val += tmp - '0';
        }
      }

      X[++idx] = val;

      /*
       * Compute.
       */
      b = (N ? 1 : 0), e = N;

      for (int i = 0; P[i] && !is_error; ++i) {
        switch (P[i]) {
          case 'R':
            if (b) {
              is_reversed = !is_reversed;
              swap(b, e);
            }
            break;
          case 'D':
            if (!b) {
              is_error = true;
            }
            else {
              if (is_reversed) {
                --b;

                if (b < e) {
                  e = b = 0;
                }
              }
              else {
                ++b;

                if (b > e) {
                  e = b = 0;
                }
              }
            }
            break;
          default:
            // do nothing
            break;
        }
      }

      /*
       * Output.
       */
      if (is_error) {
        printf("error\n");
      }
      else {
        printf("[");

        if (is_reversed) {
          for (int i = b; e < i; --i) {
            printf("%d,", X[i]);
          }
        }
        else {
          for (int i = b; e > i; ++i) {
            printf("%d,", X[i]);
          }
        }

        if (e) {
          printf("%d", X[e]);
        }

        printf("]\n");
      }

      /*
       * Reset.
       */
      is_error = is_reversed = false;
      val = idx = 0;
   }

   return 0;
}