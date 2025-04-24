a = int(input().strip())
b = int(str(a)[::-1])
op = input().strip()

print(f"{a} {op} {b} = {a + b if op == '+' else a * b}")
