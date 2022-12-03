/*
 * Title: 팀 이름 정하기
 * Link: https://www.acmicpc.net/problem/1296
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int pattern[4] = {'L', 'O', 'V', 'E'};

string answer;
int N;
string name;
vector<string> names;
long long cnt1[4], cnt2[4];
long long max_prob = -1, prob;

int main(int argc, char** argv) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   cin >> name;

   for (auto& c : name) {
      for (int i = 0; 4 > i; ++i) {
         if (c == pattern[i]) {
            ++cnt1[i];
            break;
         }
      }
   }

   cin >> N;
   for (int i = 0; N > i; ++i) {
      cin >> name;
      names.emplace_back(name);
   }
   sort(names.begin(), names.end());
   
   for (auto& name : names) {
      memcpy(cnt2, cnt1, sizeof(cnt1));
      for (auto& c : name) {
         for (int i = 0; 4 > i; ++i) {
            if (c == pattern[i]) {
               ++cnt2[i];
               break;
            }
         }
      }

      prob = ((cnt2[0] + cnt2[1]) * (cnt2[0] + cnt2[2]) * (cnt2[0] + cnt2[3]) * (cnt2[1] + cnt2[2]) * (cnt2[1] + cnt2[3]) * (cnt2[2] + cnt2[3])) % 100;
      
      if (max_prob < prob) {
         max_prob = prob;
         answer = name;
      }
   }

   cout << answer;

   return 0;
}