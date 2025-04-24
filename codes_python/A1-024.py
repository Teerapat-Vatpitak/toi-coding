year = int(input())
cc = int(input())
if year <= 1990:
    if cc <= 1500:
        tax = 1250
    elif cc <= 2000:
        tax = 1400
    else:
        tax = 2000
elif 1991 <= year <= 1999:
    if cc <= 1500:
        tax = 1100
    elif cc <= 2000:
        tax = 1300
    else:
        tax = 1700
else:
    if cc <= 1500:
        tax = 1000
    elif cc <= 2000:
        tax = 1200
    else:
        tax = 1500
print(tax)