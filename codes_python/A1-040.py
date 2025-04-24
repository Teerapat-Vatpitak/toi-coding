cal = {1:100, 2:120, 3:200, 4:60}
total = 0
while True:
    choice = int(input())
    if choice == 5:
        print("Bye Bye")
        print(f"Total Calories: {total}")
        break
    total += cal.get(choice, 0)
