def solution(n, groups):
    answer = groups.count(4)
    
    threesome = groups.count(3)
    twosome = groups.count(2)
    onesome = groups.count(1)

    answer += threesome + twosome // 2
    onesome = onesome - threesome if onesome > threesome else 0
    twosome %= 2
    
    if 0 == twosome:
        answer += onesome // 4
        if 0 != onesome % 4:
            answer += 1
    elif onesome >= 2:
        answer += 1 + (onesome - 2) // 4
        if 0 != (onesome - 2) % 4:
            answer += 1
    else:
        answer += 1
    
    return answer
    
if __name__ == "__main__":
    n = int(input())
    groups = list(map(int, input().split()))
    print(solution(n, groups))