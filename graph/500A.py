def solution(n, t, portals):
    
    cell = 1
    while cell < t:
        cell += portals[cell - 1]

    answer = "YES" if cell == t else "NO"

    return answer
    
if __name__ == "__main__":
    n, t = map(int, input().split())
    portals = list(map(int, input().split()))
    print(solution(n, t, portals))