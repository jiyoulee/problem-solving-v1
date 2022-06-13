import time

start_time = time.time()

word = input().lower()

answer = ""
for i in word:
    if i in {"a", "o", "y", "e", "u", "i"}:
        continue
    else:
        answer += "." + i

print(answer)

end_time = time.time()
print(end_time - start_time)