import sys

sys.setrecursionlimit(2500)

def dfs(graph, depth, node):
    parent = graph[node] - 1
    
    if -2 == parent or depth[node] + 1 <= depth[parent]:
        return
    
    depth[parent] = depth[node] + 1
    dfs(graph, depth, parent)

def solution(n, managers):

    depth = [1 for _ in range(n)]
    for i in range(n):
        dfs(managers, depth, i)
        
    answer = max(depth)
    
    return answer
    
if __name__ == "__main__":
    n = int(input())
    managers = [int(input()) for _ in range(n)]
    print(solution(n, managers))