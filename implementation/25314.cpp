/*
 * Title: 코딩은 체육과목 입니다
 * Link: https://www.acmicpc.net/problem/25314
 */

#include <iostream>

using namespace std;

int N;

int main(int argc, char** argv) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   cin >> N;

   for (int i = N/4; 0 < i; --i) {
      cout << "long ";
   }
   cout << "int";
   
   return 0;
}