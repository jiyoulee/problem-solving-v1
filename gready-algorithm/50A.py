def solution(M, N):
    answer = N // 2 * M if 0 == N % 2 else N // 2 * M + M // 2
    
    return answer
    
if __name__ == "__main__":
    M, N = map(int, input().split())
    print(solution(M, N))