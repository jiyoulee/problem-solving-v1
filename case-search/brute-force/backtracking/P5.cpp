/*
 * Title: 양궁대회
 * Link: https://school.programmers.co.kr/learn/courses/30/lessons/92342
 */

#include <string>
#include <vector>

using namespace std;

constexpr int RING_CNT = 10;

int max_score;
int apeach_info[RING_CNT + 1];
int lion_info[RING_CNT + 1];
int temp[RING_CNT + 1];

void go(int ring, int arrow_cnt) {
    /*
     * In the event Lion does not have any more arrows to shoot, stop searching.
     */
    if (0 == arrow_cnt) {
        int score = 0;
        for (int i = 0; RING_CNT > i; ++i) {
            if (apeach_info[i] || lion_info[i]) {
                score += ((apeach_info[i] >= lion_info[i]) ? (i - RING_CNT) : (RING_CNT - i));
            }
        }
        
        /*
         * In the event Lion wins against Apeach by a greater margin, update answer.
         */
        if (max_score < score) {
        	max_score = score;
            for (int i = 0; RING_CNT >= i; ++i) {
                temp[i] = lion_info[i];
            }
        }
        /*
         * In the event Lion wins against Apeach by the same margin and has shot more arrows on the lowest ring, update answer. 
         */
        else if (0 < score && max_score == score) {
            for (int i = RING_CNT; 0 <= i; --i) {
                if (temp[i] || lion_info[i]) {
                    if (temp[i] < lion_info[i]) {
                        for (int i = 0; RING_CNT >= i; ++i) {
                            temp[i] = lion_info[i];
                        }
                    }
                    else {
                        break;
                    }
                }
            }
        }
        return;
    }
    /*
     * In the event Lion has arrow left over to shoot but no more rings to shoot to, stop searching.
     */
    if (11 == ring) {
        return;
    }
    
    /*
     * Let Lion shoot some arrows onto the ring and then continue searching.
     */
    for (int i = 0; arrow_cnt >= i; ++i) {
        lion_info[ring] += i;
        go(ring + 1, arrow_cnt - i);
        lion_info[ring] -= i;
    }
    
    return;
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    
    /*
     * Backtrack all possible cases of arrows shot by Lion.
     */
    for (int i = 0; RING_CNT >= i; ++i) {
        apeach_info[i] = info[i];
    }
    go(0, n);
    
    /*
     * Determine whether Lion can win agaist Apeach, and get answer accordingly.
     */
    if (!max_score) {
        answer.push_back(-1);
    }
    else {
        for (int i = 0; RING_CNT >= i; ++i) {
            answer.push_back(temp[i]);
        }
    }
    
    return answer;
}