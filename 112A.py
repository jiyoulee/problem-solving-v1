first_word = input().lower()
second_word = input().lower()

if first_word < second_word: answer = -1
elif first_word > second_word: answer = 1
else: answer = 0

print(answer)