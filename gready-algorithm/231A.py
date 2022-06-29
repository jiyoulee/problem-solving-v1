def solution(problems):
    answer = 0

    for problem in problems:
        if 2 <= int(problem[0]) + int(problem[2]) + int(problem[4]):
            answer += 1
            
    return answer
    
if __name__ == "__main__":
    n = int(input())
    problems = []
    for _ in range(n):
        problems.append(input())
    print(solution(problems))