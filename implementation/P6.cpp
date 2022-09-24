/*
 * Title: 양과 늑대
 * Link: https://school.programmers.co.kr/learn/courses/30/lessons/92343
 */

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int MAX_NODE_CNT = 17;

int answer = 0;
vector<int> tree[MAX_NODE_CNT];

void go(int cur_node, int sheep_cnt, int wolf_cnt, queue<int> node_list, vector<int>& info) {
    /*
     * Count the expected number of sheeps and wolves upon advancement.
     */
    sheep_cnt += info[cur_node] ^ 1;
    wolf_cnt += info[cur_node];

    /*
     * In the event that the sheeps are predicted to be eaten, stop advancing.
     */
    if (wolf_cnt == sheep_cnt) {
        return;
    }
    
    /*
     * Advance, and the update the maximum number of sheeps obtained.
     */
    answer = max(answer, sheep_cnt);
    
    /*
     * Update lists of advancable nodes, and then try advancing to each and every one of them.
     */
    for (auto& node : tree[cur_node]) {
        node_list.emplace(node);
    }
    int next_node;
    int node_list_length = node_list.size();
    while (node_list_length--) {
        next_node = node_list.front();
        node_list.pop();

        go(next_node, sheep_cnt, wolf_cnt, node_list, info);
        
        node_list.emplace(next_node);
    }
    
    return;
}

int solution(vector<int> info, vector<vector<int>> edges) {
    /*
     * Create tree.
     */
    for (auto& edge : edges) {
        tree[edge[0]].push_back(edge[1]);
    }
    
    /*
     * Conduct a brute-force search for all possible cases of the ordering of nodes.
     */
    queue<int> node_list;
    go(0, 0, 0, node_list, info);
    
    return answer;
}