######'''Knapsack problem'''#####

memo={}
included={}
def DP(val,s,i,x):
    if i==len(val) or x==0:
        return 0
    if i in memo:
        return memo[(i,x)]
    #Not Possible to be added
    if s[i]>x:
        memo[(i,x)]=DP(val,s,i+1,x)
        included[i]=0
        return memo[(i,x)]
    else:
        #Not Added
        if DP(val,s,i+1,x)>val[i]+DP(val,s,i+1,x-s[i]):
            memo[(i,x)]=DP(val,s,i+1,x)
            included[i]=0
        #Added
        else:
            memo[(i,x)]=val[i]+DP(val,s,i+1,x-s[i])
            included[i]=1
        return memo[(i,x)]
        

'''Driver Program'''
val=[4,10,2]
s=[12,4,2]
size=15
value=DP(val,s,0,size)
print('Maximum Value:',value)
print('Subset:',end=' ')
for i in included:
    if included[i]:
        print(val[i],end=' ')
