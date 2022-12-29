/*
 * Title: 최대 힙
 * Link: https://www.acmicpc.net/problem/11279
 */

#include <cstdio>
#include <algorithm>

#define PARENT (node >> 1)
#define LEFT_CHILD (node << 1)
#define RIGHT_CHILD (node << 1 | 1)

using namespace std;

constexpr int MAX_N = 100000;

int N;
int node, size, max_child;
int max_heap[1 + MAX_N];

void push_heap(int n);
void pop_heap();

int main() {
   /*
    * Input.
    */
   scanf("%d", &N);

   /*
    * Compute and output.
    */
   for (int x; N--; ) {
      scanf("%d", &x);

      if (x) {
         push_heap(x);
      }
      else {
         pop_heap();
      }
   }

   return 0;
}

void push_heap(int n) {
   max_heap[++size] = n;

   for (node = size; 1 < node && max_heap[PARENT] < max_heap[node]; node = PARENT) {
      swap(max_heap[PARENT], max_heap[node]);
   }

   return;
}

void pop_heap() {
   if (size) {
      printf("%d\n", max_heap[1]);

      max_heap[1] = max_heap[size--];

      for (node = 1; size >= LEFT_CHILD; node = max_child) {
         max_child = (size == LEFT_CHILD || max_heap[LEFT_CHILD] >= max_heap[RIGHT_CHILD]) ? LEFT_CHILD : RIGHT_CHILD;

         if (max_heap[max_child] <= max_heap[node]) {
            break;
         }

         swap(max_heap[max_child], max_heap[node]);
      }
   }
   else {
      printf("0\n");
   }

   return;
}