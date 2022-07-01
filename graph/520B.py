from collections import deque

def bfs(n, m):
    queue = deque([(n, 0)])
    visited = {n}

    while queue:
        back = queue.popleft()
        
        if m == back[0]:
            return back[1]

        red = back[0] * 2
        blue = back[0] - 1
        if red <= 1e4 and red not in visited:
            queue.append((red, back[1] + 1))
            visited.add(red)
        if blue > 0 and blue not in visited:
            queue.append((blue, back[1] + 1))
            visited.add(blue)

def solution(n, m):

    answer = n - m if n >= m else bfs(n, m)
    
    return answer
    
if __name__ == "__main__":
    n, m = map(int, input().split())
    print(solution(n, m))