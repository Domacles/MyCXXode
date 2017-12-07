x = [int(i) for i in input().split()]
y = [int(i) for i in input().split()]

u = 0
v = 0
for i in range(len(x)):
    if x[i] >= y[i]:
        u += (x[i] - y[i]) // 2
    else:
        v += y[i] - x[i]

if u >= v:
    print('Yes')
else:
    print('No')
