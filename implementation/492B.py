def solution(n, l, locations):
    locations.sort()

    maximum_edgedistance = max(locations[0], l - locations[n - 1])
    maximum_interdistance = -1
    for i in range(len(locations) - 1):
        maximum_interdistance = max(maximum_interdistance, locations[i + 1] - locations[i])

    answer = maximum_edgedistance if maximum_edgedistance * 2 > maximum_interdistance else maximum_interdistance / 21

    return answer
    
if __name__ == "__main__":
    n, l = map(int, input().split())
    locations = list(map(int, input().split()))
    print(solution(n, l, locations))