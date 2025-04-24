a, b, c = map(int, (input(), input(), input()))
if a < b < c:
    print("increasing")
elif a > b > c:
    print("decreasing")
else:
    print("neither")