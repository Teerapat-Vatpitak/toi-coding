a, b, c = int(input()), int(input()), int(input())
m = a
if b > m:
    m = b
if c > m:
    m = c
print(f"{m}")

# m = max(a, b, c)
# print(f"{m}")