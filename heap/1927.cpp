/*
 * Title: 최소 힙
 * Link: https://www.acmicpc.net/problem/1927
 */

#include <cstdio>
#include <algorithm>

#define PARENT (node >> 1)
#define LEFT_CHILD (node << 1)
#define RIGHT_CHILD (node << 1 | 1)

using namespace std;

constexpr int MAX_N = 100000;

int N;
int size, node, min_child;
int min_heap[1 + MAX_N];

void heap_push(int n);
void heap_pop();

int main(int argc, char** argv) {
   scanf("%d", &N);

   for (int x; N--; ) {
      scanf("%d", &x);

      if (x) {
         heap_push(x);
      }
      else {
         heap_pop();
      }
   }

   return 0;
}

void heap_push(int n) {
   min_heap[++size] = n;

   for (node = size; node && min_heap[PARENT] > min_heap[node]; node = PARENT) {
      swap(min_heap[PARENT], min_heap[node]);
   }

   return;
}

void heap_pop() {
   if (size) {
      printf("%d\n", min_heap[1]);

      min_heap[1] = min_heap[size--];

      for (node = 1; size >= LEFT_CHILD; node = min_child) {
         min_child = (size == LEFT_CHILD || min_heap[LEFT_CHILD] <= min_heap[RIGHT_CHILD]) ? LEFT_CHILD : RIGHT_CHILD; 
         
         if (min_heap[min_child] >= min_heap[node]) {
            break;
         }

         swap(min_heap[node], min_heap[min_child]);
      }
   }
   else {
      printf("0\n");
   }

   return;
}