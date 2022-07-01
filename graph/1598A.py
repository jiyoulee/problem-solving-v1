dx = [1, -1, 0, 0, -1, -1, 1, 1]
dy = [0, 0, -1, 1, -1, 1, -1, 1]

def dfs(graph, visited, x, y, tx, ty):
    global dx, dy

    if tx == x and ty == y:
        return True
    
    visited[x][y] = True
   
    for i in range(8):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx and nx <= 1 and 0 <= ny and ny <= ty and "0" == graph[nx][ny] and not visited[nx][ny]:
            if dfs(graph, visited, nx, ny, tx, ty):
                return True

    return False
    
def solution(t, games):
    answer = []

    for k in range(t):
        visited = [[False] * games[k][0] for _ in range(games[k][0])]
        answer.append("YES" if dfs(games[k][1], visited, 0, 0, 1, games[k][0] - 1) else "NO")

    answer = "\n".join(map(str, answer))
    
    return answer
    
if __name__ == "__main__":
    t = int(input())
    games = [[int(input()), [input(), input()]] for _ in range(t)]
    print(solution(t, games))