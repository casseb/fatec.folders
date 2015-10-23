def fat(n):
    f = 1
    while n > 0:
        f = f * n
        n = n - 1
    return f

def fatInvert(n):
    f = n
    while n < 0:
        f = f * n
        n = n + 1
    return f

for i in range(50): print (fat(i))
for i in range(50): print (fatInvert(i))

