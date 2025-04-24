roman = {i: r for i, r in enumerate(
    ["","I","II","III","IV","V","VI","VII","VIII","IX"])}
n = int(input())
if n <= 0:
    print("Error : Please input positive number")
elif n <= 9:
    print(roman[n])
else:
    print("Error : Out of range")