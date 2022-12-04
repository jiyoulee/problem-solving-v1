/*
 * Title: 유진수
 * Link: https://www.acmicpc.net/problem/1356
 */

#include <cstdio>

int l;
char C[11];
long long partial_product[2][10];

int main(int argc, char** argv) {
   scanf("%s", C);

   /*
    * Get partial products.
    */
   for (;'\0' != C[l]; ++l) {
      partial_product[1][l] = partial_product[0][l] = C[l] - '0';
   }
   for (int i = 1, j = l - 2; l > i; ++i, --j) {
      partial_product[0][i] *= partial_product[0][i - 1];
      partial_product[1][j] *= partial_product[1][j + 1];
   }

   /*
    * Compare partial products.
    */
   for (int i = 1; l > i; ++i) {
      if (partial_product[0][i - 1] == partial_product[1][i]) {
         printf("YES");

        return 0;
      }
   }

   printf("NO");

   return 0;
}