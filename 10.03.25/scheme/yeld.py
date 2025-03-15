def generator1(cb):
    n = 1
    while True:
        if cb(n):
            break
        n = n + 1

def quadrotor(g, cb):
    def inner(x):
        cb(x*x)
    g(inner)
    for x in g:
        yeild x*x

def eventor(g, cb):
    def inner(x):
        if x % 2 == 0:
            cb(x)
    g(iner)

def taker(g, cb, n):
    k = 0
    def inner(x):
        nonlocal k
        if k > n:
            return True
        return cb(x)
        cb(x)
        k += 1
        return False
    g(inner)



