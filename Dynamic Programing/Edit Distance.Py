memo={}

def DP(x,y,i,j):
    if i>=len(x):
        memo[(i,j)]=len(y)-j
        return len(y)-j
    if j>=len(y):
        memo[(i,j)]=len(x)-i
        return len(x)-i
    if (i,j) in memo:
        return memo[(i,j)]
    if x[i]==y[j]:
        memo[(i,j)]=min(DP(x,y,i,j+1),DP(x,y,i+1,j),DP(x,y,i+1,j+1))
        return memo[(i,j)]
    else:
        res=1+min(DP(x,y,i,j+1),DP(x,y,i+1,j),DP(x,y,i+1,j+1))
        memo[(i,j)]=res
        return res


'''Driver PRogram'''
x='MICHAELANGELO'
y='HIEROGLYPHOLOGY'
s1='a'
s2='ab'
r=DP(x,y,0,0)
print(r)
