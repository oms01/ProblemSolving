n = int(input())
if(n==0):
    print(1)
    exit(0)
for i in range(1,n):
    n*=i

print(n)