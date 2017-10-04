import math
memo={}
parent={}
def badness(i,j,m):
    totsize=0
    extra=0
    for x in range(i,j):
        totsize+=len(ls[x])
        extra+=1
    totsize+=extra-1
    if m>=totsize:
        return ((m-totsize)**3)
    else:
        return math.inf

def minimum(i,ls,w,n):
    p=[]
    for j in range(i+1,n+1):
        p+=[DP(j,ls,w,n)+badness(i,j,w)]
    parent[i]=p.index(min(p))+i+1
    return min(p)

def DP(i,ls,w,n):
    if i in memo:
        return memo[i]
    if i==n:
        parent[n]=None
        return 0
    else:
        #t= min(DP(j,ls,w,n)+badness(i,j,w) for j in range(i+1,n+1))
        t=minimum(i,ls,w,n)
        memo[i]=t
        return t

'''Driver Code'''

s='aaa bb cc ddddd'
ls=s.split()
print('Sample Text:',s)
words=len(ls)
width=6
DP(0,ls,width,words)

#printing text

p=0
while parent[p]!=None:
    print(*ls[p:parent[p]])
    p=parent[p]
