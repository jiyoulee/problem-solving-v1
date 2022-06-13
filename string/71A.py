n = int(input())

for i in range(n):
    word = input()
    
    if len(word) <= 10:
        answer = word
    else:
        answer = word[0] + str(len(word[1:-1])) + word[-1]

    print(answer)