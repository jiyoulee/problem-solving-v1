/*
 * Title: Easy work
 * Link: https://www.acmicpc.net/problem/7785
 */

#include <iostream>
#include <cstring>
#include <functional>
#include <map>
using namespace std;

int answer;
int N;
string name;
map<string,string,greater<string>> m;

int main(int argc, char** argv) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   cin >> N;
   while (N--) {
      cin >> name >> m[name];
   }

   for (auto& e : m) {
      if ("enter" == e.second) {
         cout << e.first << "\n";
      }
   }

   return 0;
}