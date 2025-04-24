n = int(input())
count = 0
for _ in range(n):
    if input().strip() in "AEIOU":
        count += 1
print(count)
