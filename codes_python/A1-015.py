name    = input("")
surname = input("")
age     = input("")

print(f"{name[:2]}{surname[-1]}{age[-1]}" if len(name) >= 5 and len(surname) >= 5 else f"{name[:1]}{age}{surname[-1]}")
