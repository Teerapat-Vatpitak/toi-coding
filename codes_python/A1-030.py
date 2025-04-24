n = int(input())
nums = list(map(int, input().split()))
maxes = [max(nums[i*2], nums[i*2+1]) for i in range(n)]
if n == 1:
    print(maxes[0])
else:
    total = sum(maxes)
    print(" + ".join(map(str, maxes)) + " = " + str(total))