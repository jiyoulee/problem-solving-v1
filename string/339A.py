s = input().split("+")

s.sort()

answer = s[0]
for i in s[1:]:
    answer += "+" + i

print(answer)