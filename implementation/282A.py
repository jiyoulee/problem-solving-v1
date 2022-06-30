def solution(statements):
    answer = 0

    for statement in statements:
        answer += 1 if "+" in statement else -1
    
    return answer
    
if __name__ == "__main__":
    n = int(input())
    statements = []
    for _ in range(n):
        statements.append(input())
    print(solution(statements))