def solution(requests):
    answer = []

    database = {}

    for request in requests:
        if request not in database:
            database[request] = 0
            answer.append("OK")
        else:
            database[request] += 1
            new_request = "".join([request, str(database[request])])
            database[new_request] = 0
            answer.append(new_request)

    answer = "\n".join(answer)
    
    return answer
    
if __name__ == "__main__":
    n = int(input())
    requests = [input() for _ in range(n)]
    print(solution(requests))