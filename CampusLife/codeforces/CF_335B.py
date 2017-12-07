M, N, x, y = input().split()
s = input()
M = int(M)
N = int(N)
x = int(x) - 1
y = int(y) - 1

ans = [0 for i in range(len(s) + 10)]
has = [[0 for j in range(N)] for i in range(M)]
has[x][y] = 1
c = 1
ans[0] = 1
for i in range(len(s) - 1):
    if s[i] == 'U' and x - 1 >= 0:
        x -= 1
    if s[i] == 'D' and x + 1 < M:
        x += 1
    if s[i] == 'L' and y - 1 >= 0:
        y -= 1
    if s[i] == 'R' and y + 1 < N:
        y += 1
    if(has[x][y] == 0):
        c += 1
        ans[i + 1] = has[x][y] = 1
for i in range(len(s)):
    print(ans[i], end=' ')
print(M * N - c)
