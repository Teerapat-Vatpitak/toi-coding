c = str(input())
pwd = int(input())

if c != 'H' and pwd != 4567:
    print('safe locked')
elif c == 'H' and pwd != 4567:
    print('safe locked - change digit')
elif c != 'H' and pwd == 4567:
    print('safe locked - change char')
elif c == 'H' and pwd == 4567:
    print('safe unlocked')