a = int(input())
b = int(input())
c = int(input())
even = (a % 2 == 0) + (b % 2 == 0) + (c % 2 == 0)
odd = 3 - even
print(f"even {even}")
print(f"odd {odd}")