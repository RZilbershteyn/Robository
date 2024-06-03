n, b = [int(i) for i in input().split()]
sequence = [int(i) for i in input().split()]

def check(a, bias):
    if a == []:
        return False
    if list(sorted(a)) == a:
        if all([a[i + 1] <= a[i] + bias for i in range(len(a) - 1)]):
            return True
    
    return False

def nextmask(m):
    i = 0
    while m[i] != 0:
        m[i] = 0
        i += 1
        
        if i == len(m):
            return -1
    
    m[i] = 1
    
    return m

mask = [0] * n
res = 0

while mask != -1:
    tmpsequence = sequence.copy()
    k = 0
    for i in range(n):
        if mask[i]:
            del tmpsequence[i - k]
            k += 1
    
    if check(tmpsequence, b):
        res = max(res, len(tmpsequence))
    
    mask = nextmask(mask)

print(res)