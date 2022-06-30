def solution(n, vectors):
    x, y, z = 0, 0, 0
    for vector in vectors:
        x += vector[0]
        y += vector[1]
        z += vector[2]

    answer = "YES" if 0 == x and 0 == y and 0 == z else "NO"
    
    return answer
    
if __name__ == "__main__":
    n = int(input())
    vectors = [list(map(int, input().split())) for _ in range(n)]
    print(solution(n, vectors))