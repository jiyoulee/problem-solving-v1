def solution(n, columns):
    answer = []
    
    columns.sort()
    
    answer = " ".join(map(str, columns))
    
    return answer
    
if __name__ == "__main__":
    n = int(input())
    columns = list(map(int, input().split()))
    print(solution(n, columns))