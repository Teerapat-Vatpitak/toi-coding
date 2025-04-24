vals = [input() for _ in range(3)]
u = len(set(vals))
if u == 1:
    print("all the same")
elif u == 3:
    print("all different")
else:
    print("neither")