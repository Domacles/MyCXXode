N = int(input())
a = [0 for x in range(N)]
A = [int(x) for x in input().split()]

for i in range(len(A)):
    a[A[i]-1] = i

now=1
ans=0
for i in range(1,len(a)):
    if a[i]>a[i-1]:
        now+=1
    else:
        ans=max(ans,now)
        now=1

print(N-ans)

