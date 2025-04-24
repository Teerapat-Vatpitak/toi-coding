t = int(input())
unit = input().strip().upper()
if unit == "C":
    if t <= 0:
        state = "solid"
    elif t >= 100:
        state = "gas"
    else:
        state = "liquid"
else:
    if t <= 32:
        state = "solid"
    elif t >= 212:
        state = "gas"
    else:
        state = "liquid"
print(state)
