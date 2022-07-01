t = int(input())
array_lengths = []
arrays = []
for _ in range(t):
    array_lengths.append(int(input()))
    arrays.append(list(map(int, input().split())))
    
answer = []

for k in range(t):
    temp_answer = -1
    for i in range(array_lengths[k]):
        node = i
        while array_lengths[k] > node:
            if 0 == arrays[k][node]:
                break
    
            new_node = node + arrays[k][node]
            arrays[k][node] = 0
            node = new_node
        if array_lengths[k] <= node:
            temp_answer = max(temp_answer, node - i)
    answer.append(temp_answer)

answer = "\n".join(map(str, answer))
        
print(answer)