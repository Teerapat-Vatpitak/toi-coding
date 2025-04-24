s = input().strip()
rank = s[:-1].upper()
suit = s[-1].upper()
rank_names = {"A": "ace", "J": "jack", "Q": "queen", "K": "king"}
name = rank_names.get(rank, rank)
suit_names = {"D": "diamonds", "H": "hearts", "S": "spades", "C": "clubs"}
group = suit_names[suit]
print(f"{name} of {group}")