#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int cnt;
    vector<int> answer;
    
    reverse(progresses.begin(), progresses.end());
    reverse(speeds.begin(), speeds.end());
    
    while (!progresses.empty()) {
        for (int i = 0; i < progresses.size(); i++) {
            progresses[i] += speeds[i];
        }
        
        cnt = 0;
        while (!progresses.empty() && 100 <= progresses.back()) {
            progresses.pop_back();
            speeds.pop_back();
            cnt++;
        }
        if (cnt > 0) {
            answer.push_back(cnt);
        }
    }
    
    return answer;
}