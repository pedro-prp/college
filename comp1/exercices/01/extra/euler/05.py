x = 1

while 1:
    w = True
    for i in range(1, 21):
        if x % i != 0:
            w = False
            break
    if w:
        break
    x += 1

print(x)
