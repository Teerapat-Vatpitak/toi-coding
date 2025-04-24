n = int(input())
print("".join("X" if i % 5 == 0 else "*" for i in range(1, n+1)))
