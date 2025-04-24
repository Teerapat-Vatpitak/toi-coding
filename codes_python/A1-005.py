m = int(input())
d = int(input())
seasons = ["winter", "spring", "summer", "fall"]
idx = (m // 3) % 4 if m % 3 == 0 and d >= 21 else (m - 1) // 3
print(seasons[idx])
