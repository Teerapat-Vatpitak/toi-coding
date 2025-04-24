n = int(input())
res = []
for i in range(n, -1, -1):
    if i % 10 == 0:
        res.append(str(i))
print(" ".join(res))
