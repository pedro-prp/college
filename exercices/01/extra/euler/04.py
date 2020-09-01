n = 0

for i in range(1000):
    for j in range(1000):
        r = (i*j)
        if str(r) == str(r)[::-1] and r > n:
            n = r

print(n)
