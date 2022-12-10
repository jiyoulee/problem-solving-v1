def solution(n, values):
    answer = 0

    values.sort(reverse=True)
    
    half_share = sum(values) / 2
    for i in range(len(values)):
        if sum(values[:i + 1]) > half_share:
            answer = i + 1
            break

    return answer
    
if __name__ == "__main__":
    n = int(input())
    values = list(map(int,input().split()))
    print(solution(n, values))