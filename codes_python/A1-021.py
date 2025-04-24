year = int(input())
if year < 1582:
    is_leap = (year % 4 == 0)
else:
    is_leap = (year % 400 == 0) or (year % 4 == 0 and year % 100 != 0)
    
print("yes" if is_leap else "no")
