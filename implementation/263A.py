def solution(matrix):
    for i in range(5):
        if 1 in matrix[i]:
            x = i
            y = matrix[i].index(1)
            break

    answer += abs(x - 2) + abs(y - 2)
    
    return answer
    
if __name__ == "__main__":
    matrix = []
    for _ in range(5):
        matrix.append(list(map(int, input().split())))
    print(solution(matrix))