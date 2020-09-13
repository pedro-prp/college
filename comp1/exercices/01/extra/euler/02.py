def fib(p=1, n=2, r=[1, 2]):
    if (n + p) % 2 == 0:
        r.append(n + p)

    p, n = n, (p+n)

    return p, n, r


x = 10
p, n, r = fib()
for i in range(x):
    p, n, r = fib(p, n, r)

print(r)
