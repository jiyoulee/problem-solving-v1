def solution(n, k, scores):
    answer = 0
    
    for score in scores:
        if score >= scores[k - 1] and score > 0:
            answer += 1
            
    return answer
    
if __name__ == "__main__":
    n, k = map(int, input().split())
    scores = list(map(int, input().split()))
    print(solution(n, k, scores))