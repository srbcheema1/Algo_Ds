import math
memo={}
piece={}

def cut_rod(p,n):
    if n==0:
        return 0
    if n in memo:
        return memo[n]
    else:
        q=-1
        for i in range(1,n+1):
            #q=max(q,p[i]+cut_rod(p,n-i))
            if q<p[i]+cut_rod(p,n-i):
                q=p[i]+cut_rod(p,n-i)
                piece[n]=i
        memo[n]=q
        return q
        
'''Driver Program'''
p={1:1,2:5,3:8,4:9,5:10,6:17,7:17,8:20,9:24,10:30}
n=5
cut_rod(p,n)

while(n>0):
    print (piece[n])
    n-=piece[n]
