day = int(input())
month = int(input())
if (month == 12 and day >= 22) or (month == 1 and day <= 19):
    sign = "capricorn"
elif (month == 1 and day >= 20) or (month == 2 and day <= 18):
    sign = "aquarius"
elif (month == 2 and day >= 19) or (month == 3 and day <= 20):
    sign = "pisces"
elif (month == 3 and day >= 21) or (month == 4 and day <= 19):
    sign = "aries"
elif (month == 4 and day >= 20) or (month == 5 and day <= 20):
    sign = "taurus"
elif (month == 5 and day >= 21) or (month == 6 and day <= 21):
    sign = "gemini"
elif (month == 6 and day >= 22) or (month == 7 and day <= 22):
    sign = "cancer"
elif (month == 7 and day >= 23) or (month == 8 and day <= 22):
    sign = "leo"
elif (month == 8 and day >= 23) or (month == 9 and day <= 22):
    sign = "virgo"
elif (month == 9 and day >= 23) or (month == 10 and day <= 23):
    sign = "libra"
elif (month == 10 and day >= 24) or (month == 11 and day <= 21):
    sign = "scorpio"
else:
    sign = "sagittarius"
print(sign)
