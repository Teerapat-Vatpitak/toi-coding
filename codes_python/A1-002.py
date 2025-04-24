n = int(input())
coins = [10, 5, 2, 1]
for coin in coins :
    count = n // coin
    print(f"{coin} = {count}")
    n = n % coin